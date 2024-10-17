#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_VECTOR_CAPACITY 3
#define INVALID_INDEX           1
#define SUCCESS                 0

typedef struct findRepl {
    char *find;
    char *repl;
} findRepl;

typedef struct vector {
    void  *elements;
    size_t elementSize;
    size_t capacity;
    size_t count;
} vector;

/**
 * Creates a vector object with an inicial capacity
 * of _capacity for elements of size _elementSize.
 * Vector must be destroyed with the right function.
 *
 * @param capacity Inicial vector capacity
 * @param elementSize Size in bytes of each element
 * @return Pointer to vector object
 */
vector *newVector(size_t capacity, size_t elementSize) {
    // Create the vector object
    vector *v = malloc(sizeof(vector));

    // Allocate memory to store the elements
    v->elements    = malloc(elementSize * capacity);
    v->elementSize = elementSize; // Store element size
    v->capacity    = capacity;    // Store vector capacity
    v->count       = 0;           // Update element count
    return v;
}

/**
 * Checks if a vector object is full.
 *
 * @param v Vector to check
 * @return 1 if full, 0 otherwise
 */
int vectorIsFull(const vector *const v) { return v->count == v->capacity; }

/**
 * Increase the size of a vector object.
 * Doubling it's capacity.
 */
void increaseVectorSize(vector *const v) {
    void *newMem = malloc(2 * v->capacity * v->elementSize);
    memcpy(newMem, v->elements, v->capacity * v->elementSize);
    free(v->elements);
    v->elements  = newMem;
    v->capacity *= 2;
}

/**
 * Add an element to a vector.
 *
 * @param v Vector
 * @param element Pointer to the new element
 */
void vectorAddElement(vector *const v, const void *const element) {
    if (vectorIsFull(v)) increaseVectorSize(v);

    void *destination = (char *)v->elements + v->count * v->elementSize;
    memcpy(destination, element, v->elementSize);
    v->count++;
}

/**
 * Set _element to element at _index of _v.
 *
 * @param v Vector
 * @param index Index to read
 * @param element Pointer where to write the element to
 * @return Error code
 */
int vectorAt(vector *const v, size_t index, void *const element) {
    if (index >= v->count) return INVALID_INDEX;

    void *p = (char *)v->elements + index * v->elementSize;
    memcpy(element, p, v->elementSize);

    return SUCCESS;
}

int myGetLine(char **const linePtr, size_t *const n, FILE *const stream) {
    if (stream == NULL) return -1;

    const size_t bufferSize = 1024;
    size_t       lineSize   = 0;
    size_t       len        = 0;

    char *line   = NULL;
    char *buffer = malloc(sizeof(char) * bufferSize);
    char *tempLine;

    while (fgets(buffer, bufferSize, stream) != NULL) {
        // Allocate new memory with Line + Buffer length
        tempLine = malloc(sizeof(char) * (lineSize + bufferSize - 1));
        // Last byte 0x0 is not copied so that string remains contiguous

        // Copy Line into new space
        memcpy(tempLine, line, lineSize);
        // Copy buffer into new space after line
        memcpy(tempLine + lineSize, buffer, bufferSize - 1);

        free(line);                 // Delete previous line
        line      = tempLine;       // Change reference to new memory
        lineSize += bufferSize - 1; // Update lineSize


        if ((len = strlen(buffer)) != bufferSize - 1
            || (len == bufferSize - 1 && buffer[bufferSize - 2] == '\n')) {
            // Buffer is not full which means line is done reading,
            // Or buffer is full but it's the end of the line;
            break;
        }
    }
    // EOF, no more to read
    free(buffer);
    *linePtr = line;
    *n       = lineSize;
    return len;
}

char *str_replace(const char *orig, const char *const repl, const char *with) {
    size_t len_front;
    size_t lenRepl;
    size_t lenWith;
    size_t count;
    char  *ins;
    char  *tmp;
    char  *result;

    if (orig == NULL || repl == NULL) return NULL;

    lenRepl = strlen(repl);
    if (lenRepl == 0) return NULL;

    if (with == NULL) with = "";
    lenWith = strlen(with);

    // Count replacements needed
    ins = orig;
    for (count = 0; (tmp = strstr(ins, repl)); count++) ins = tmp + lenRepl;

    tmp = result = malloc(strlen(orig) + 1 + count * (lenWith - lenRepl));
    if (result == NULL) return NULL;

    while (count--) {
        ins        = strstr(orig, repl);
        len_front  = ins - orig;
        tmp        = strncpy(tmp, orig, len_front) + len_front;
        tmp        = strcpy(tmp, with) + lenWith;
        orig      += len_front + lenRepl;
    }
    strcpy(tmp, orig);
    return result;
}

int main(int argc, char *argv[]) {
    // Create vector of findRepl objects
    vector *settings = newVector(DEFAULT_VECTOR_CAPACITY, sizeof(findRepl));

    {
        findRepl fr;
        char    *str;
        char    *middle;
        for (size_t i = 1; i < argc; i++) {
            str = argv[i];

            middle = strstr(str, "-");
            if (middle == NULL) {
                printf("Invalid argument: \"%s\"", str);
                continue;
            }

            fr.repl = malloc(strlen(middle + 1) + 1);
            strcpy(fr.repl, middle + 1);

            fr.find = malloc(middle - str + 1);
            memcpy(fr.find, str, middle - str);
            fr.find[middle - str] = 0;

            vectorAddElement(settings, &fr);
        }
    }

    char    *line;
    char    *line2;
    size_t   len;
    findRepl setting;
    while (myGetLine(&line, &len, stdin)) {
        for (size_t i = 0; i < settings->count; i++) {
            vectorAt(settings, i, &setting);
            line2 = str_replace(line, setting.find, setting.repl);
            free(line);
            line = line2;
        }
        printf("%s", line2);
    }

    exit(EXIT_SUCCESS);
}
