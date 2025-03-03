int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // This variable stores the max sum reached
    // By default it is at least the first element of the array
    int maxSum = A[0];

    // Loop through each combination of start and end positions
    for (unsigned int ii = 0; ii < n; ii++) {
        // Store the local sum of elements
        // Here the sum starts at 0, because the first element
        // will be added inside the loop
        int localSum = 0;
        for (unsigned int jj = ii; jj < n; jj++) {
            // Add element to the local sum
            localSum += A[jj];

            // Compare local sum to the global max sum
            if (localSum > maxSum) {
                // Update max sum
                maxSum = localSum;

                // Update start and end positions
                i = ii;
                j = jj;
            }
        }
    }

    return maxSum;
}
