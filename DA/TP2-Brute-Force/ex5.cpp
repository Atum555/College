void changeMakingBFAux(
    unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T,
    unsigned int usedCoins[], unsigned int index, unsigned int &bestCoinCount,
    unsigned int tempUsedCoins[]
) {
    // If T is zero a solution has been found
    if (T == 0) {
        // Count coins used
        unsigned int coinCount = 0;
        for (unsigned int i = 0; i < n; i++) coinCount += tempUsedCoins[i];

        // If a better solution has been found
        if (coinCount < bestCoinCount or bestCoinCount == 0) {
            bestCoinCount = coinCount;

            // Update the used coins list
            for (unsigned int i = 0; i < n; i++) usedCoins[i] = tempUsedCoins[i];
        }
        return;
    }

    // All coins have been checked and no solution found
    if (index >= n) return;

    // For the coin at index (index) try every number of coins from 0 to Stock[index]
    // If it doesn't surpass the remaining target
    for (unsigned int i = 0; i <= Stock[index] && C[index] * i <= T; i++) {
        tempUsedCoins[index] = i;
        changeMakingBFAux(
            C, Stock, n, T - C[index] * i, usedCoins, index + 1, bestCoinCount, tempUsedCoins
        );
    }

    // Reset the current coin count
    tempUsedCoins[index] = 0;
}

bool changeMakingBF(
    unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]
) {
    // Reset usedCoins list
    for (unsigned int i = 0; i < n; i++) usedCoins[i] = 0;

    // Init best coin count and tempUsedCoins
    unsigned int bestCoinCount    = 0;
    unsigned int tempUsedCoins[n] = { 0 };

    // Recursively check all combinations
    changeMakingBFAux(C, Stock, n, T, usedCoins, 0, bestCoinCount, tempUsedCoins);

    // If best coin count is different from 0, then a solution has been found
    return bestCoinCount != 0;
}

bool changeMakingGR(
    unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]
) {
    // For each coin in reverse order
    for (int i = n - 1; i >= 0; i--) {
        // Use as many coins as possible
        unsigned int coinsToUse = T / C[i];
        if (coinsToUse > Stock[i]) coinsToUse = Stock[i];

        T            -= coinsToUse * C[i];
        usedCoins[i]  = coinsToUse;
    }

    return T == 0;
}
