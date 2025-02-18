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
