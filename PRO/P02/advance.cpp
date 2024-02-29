void advance(int delta, int &d, int &m, int &y) {
    d += delta;

    bool doit = true;
    while (doit) {
        switch (m) {
        case 2: {
            int maxD
                = y % 4 == 0 ? (y % 100 ? (y % 400 ? 29 : 28) : (29)) : (28);
            if (d > maxD) {
                d -= maxD;
                ++m;
            } else doit = false;
            break;
        }
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if (d > 31) {
                d -= 31;
                ++m;
            } else doit = false;
            break;
        }
        default: {
            if (d > 30) {
                d -= 30;
                ++m;
            } else doit = false;
            break;
        }
        }
        if (m > 12) {
            m = 1;
            ++y;
        }
    };
}