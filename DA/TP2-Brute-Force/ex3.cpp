unsigned int knapsackBF(
    unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight,
    bool usedItems[]
) {
    // Init global max value found
    unsigned int maxValue     = 0;
    unsigned int maxValueMask = 0;

    // Create a mask that represents whether elements are in
    // the subset or not
    // Loop through all the combinations of the elements
    // using the mask
    for (unsigned int mask = 1; mask < (1u << n); mask++) {
        // Calculate the weight of all the elements in the current subset
        unsigned int weight = 0;
        for (unsigned int i = 0; i < n; i++)
            // Add the element if it is in the mask
            if ((mask >> i) & 1) weight += weights[i];

        // If weight is more than the max weight ignore subset
        if (weight > maxWeight) continue;

        // Calculate the value of all the elements in the current subset
        unsigned int value = 0;
        for (unsigned int i = 0; i < n; i++)
            // Add the element if it is in the mask
            if ((mask >> i) & 1) value += values[i];

        // Better solution found
        // Update max value and mask
        if (value > maxValue) {
            maxValue     = value;
            maxValueMask = mask;
        }
    }

    // Convert mask into the bool array
    for (unsigned int i = 0; i < n; i++)
        // Add the element if it is in the mask
        if ((maxValueMask >> i) & 1) usedItems[i] = true;
        else usedItems[i] = false;

    return maxValue;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyValue(
    unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight,
    bool usedItems[]
) {
    // Reset usedItems list
    for (unsigned int i = 0; i < n; i++) usedItems[i] = false;

    // Init weight and value tracker
    unsigned int weight = 0;
    unsigned int value  = 0;

    // Try to find the next item with the most value that fits in the bag
    while (weight < maxWeight) {
        // Local best item
        int bestItem      = -1;
        int bestItemValue = -1;

        // For every item
        for (unsigned int i = 0; i < n; i++) {
            // If already in the bag ignore
            if (usedItems[i]) continue;

            // If weight exceed max ignore
            if (weight + weights[i] > maxWeight) continue;

            // If better value than current best item, replace it
            if ((int)values[i] > bestItemValue) {
                bestItem      = i;
                bestItemValue = values[i];
            }
        }

        // If no item found that will fit in the bag
        // Stop the search
        if (bestItem == -1) break;

        // Else mark it as used and increase weight and value sum
        usedItems[bestItem]  = true;
        weight              += weights[bestItem];
        value               += bestItemValue;
    }

    return value;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyWeight(
    unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight,
    bool usedItems[]
) {
    // Reset usedItems list
    for (unsigned int i = 0; i < n; i++) usedItems[i] = false;

    // Init weight and value tracker
    unsigned int weight = 0;
    unsigned int value  = 0;

    // Try to find the next item with the most value that fits in the bag
    while (weight < maxWeight) {
        // Local best item
        int bestItem       = -1;
        int bestItemWeight = -1;

        // For every item
        for (unsigned int i = 0; i < n; i++) {
            // If already in the bag ignore
            if (usedItems[i]) continue;

            // If weight exceed max ignore
            if (weight + weights[i] > maxWeight) continue;

            // If better weight than current best item, replace it
            if ((int)weights[i] < bestItemWeight or bestItemWeight == -1) {
                bestItem       = i;
                bestItemWeight = weights[i];
            }
        }

        // If no item found that will fit in the bag
        // Stop the search
        if (bestItem == -1) break;

        // Else mark it as used and increase weight and value sum
        usedItems[bestItem]  = true;
        weight              += weights[bestItem];
        value               += values[bestItem];
    }

    return value;
}
