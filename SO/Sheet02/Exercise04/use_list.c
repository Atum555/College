#include "list.h"

int main() {
    list *l = list_new_random(15, 100);
    list_print(l);
    for (unsigned i = 0; i < 10; i++) list_remove_first(l);
    list_print(l);
    list_add_first(69, l);
    list_print(l);
    return 0;
}
