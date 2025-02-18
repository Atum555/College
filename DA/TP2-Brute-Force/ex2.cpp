// By: Gonçalo Leão
// Updated by DA 24/25 Team

bool subsetSumBF(
    unsigned int A[], unsigned int n, unsigned int T, unsigned int subset[],
    unsigned int &subsetSize
) {
    // Init default subset size, needed for tests to run
    subsetSize = 0;

    // Create a mask that represents whether elements are in
    // the subset or not
    // Loop through all the combinations of the elements
    // using the mask
    for (unsigned int mask = 1; mask < (1u << n); mask++) {
        // Calculate the sum of all the elements in the current subset
        unsigned int sum = 0;
        for (unsigned int i = 0; i < n; i++)
            // Add the element if it is in the mask
            if ((mask >> i) & 1) sum += A[i];

        // If sum equals the target value, solution found
        if (sum == T) {
            // Add elements in the mask to the subset array
            for (unsigned int i = 0; i < n; i++)
                if ((mask >> i) & 1) subset[subsetSize++] = A[i];
            return true;
        }
    }

    // No solution found
    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

unsigned int sum(unsigned int A[], unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++) { sum += A[i]; }
    return sum;
}

// Checks if A is a subset of B
bool isSubset(unsigned int A[], unsigned int nA, unsigned int B[], unsigned int nB) {
    for (unsigned int i = 0; i < nA; i++) {
        bool foundNum = false;
        for (unsigned int j = 0; j < nB; j++) {
            if (A[i] == B[j]) {
                foundNum = true;
                break;
            }
        }
        if (!foundNum) return false;
    }
    return true;
}

TEST(TP2_Ex2, testSubsetSum) {
    unsigned int A[] = { 3, 34, 4, 12, 5, 2 };
    unsigned int subset[6];
    unsigned int subsetSize;

    unsigned int T = 9;
    EXPECT_EQ(subsetSumBF(A, 6, T, subset, subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A, 6), true);

    T = 20;
    EXPECT_EQ(subsetSumBF(A, 6, T, subset, subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A, 6), true);

    T = 30;
    EXPECT_EQ(subsetSumBF(A, 6, T, subset, subsetSize), false);
}
