void int_to_str(const int n, char str[], int &pos) {
    int j = 0; // Digit Count
    int a = n; // Safe Copy

    // Count Digits
    while (a) {
        ++j;
        a /= 10;
    }
    a          = n; // Restore Safe Copy
    int offSet = j; // Safe Copy

    // Write Digits
    while (a) {
        --j;
        str[pos + j]  = (a % 10) + '0';
        a            /= 10;
    }
    pos += offSet;
}

void rle_encode(const char str[], char rle[]) {
    int  i     = 0;
    int  pos   = 0;
    char c     = 0;
    int  count = 0;

    while (true) {
        char l = str[i];

        if (i == 0) {
            // Empty String
            if (l == 0) {
                rle[0] = 0;
                return;
            }

            c = l;
            ++count;
            ++i;
            continue;
        }

        // Write if caracter is diferente
        if (c != l) {
            // Write Count
            int_to_str(count, rle, pos);
            // Write Char
            rle[pos] = c;
            ++pos;

            // Change Char and Update Count
            c     = l;
            count = 1;
        }
        // Increment Count if caracter doesn't change
        else {
            ++count;
        }

        // Break on String End
        if (l == 0) {
            rle[pos] = 0;
            return;
        }

        // Increment position
        ++i;
    }
}
