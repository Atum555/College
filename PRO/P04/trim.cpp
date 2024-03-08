void trim(char s[]) {
    bool start        = true;
    int  i            = 0;
    int  offSet       = 0;
    int  spaceCounter = 0;
    while (char l = s[i]) {
        if (l == ' ') {
            if (start) {
                ++offSet;
                ++i;
                continue;
            }
            ++spaceCounter;
        } else {
            start = false;
            for (int j = 0; j < spaceCounter; j++)
                s[i - offSet - spaceCounter + j] = ' ';
            s[i - offSet] = s[i];
            spaceCounter  = 0;
        }
        ++i;
    }
    if (spaceCounter) s[i - offSet - spaceCounter] = 0;
    else s[i - offSet] = s[i];
}