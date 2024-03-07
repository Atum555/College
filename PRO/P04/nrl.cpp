int nrl(const char s[], char low[]) {
    // Represent presence of a letter as a 1 in a binary number
    // "acd" pode ser traduzido para "0b00...001101"
    //
    // Conversao:
    // 0b00...00.0000.0000.0000.0000.0000.0000.0000
    //             zy.xwvu.tsrq.ponm.lkji.hgfe.dcba
    //
    // When a letter is found it's representation is added to unique.
    // If it is already in found it is then removed from unique
    //

    int unique = 0;
    int found  = 0;
    int i      = 0;
    while (char l = s[i]) {                                 // Select letter
        int lInt = 0;
        if ('a' <= l && l <= 'z') lInt = 1 << (l - 'a');    // Binary number 1 right shifted by letter number
        if ('A' <= l && l <= 'Z') lInt = 1 << (l - 'A');
        if (lInt) {
            unique |= lInt;                     // Add letter to unique
            if (found & lInt) unique &= ~lInt;  // Remove letter from unique if in found
            found |= lInt;                      // Add letter to found
        }
        ++i;
    }

    int c = 0;
    for (int i = 0; i < 26; ++i) {
        if (unique & 1) {               // For each bit, if 1
            low[c] = 'a' + i;           // Add corresponding letter to result string
            ++c;                        // Increment letter counter
        }
        unique >>= 1;                   // Shift letter representation
    }

    low[c] = 0;                         // Add Null caracter
    return c;
}