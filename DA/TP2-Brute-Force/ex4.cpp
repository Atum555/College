#include <algorithm>

double fractionalKnapsackGR(
    unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight,
    double usedItems[]
) {
    // Reset usedItems list
    for (unsigned int i = 0; i < n; i++) usedItems[i] = 0;

    // Init weight and value tracker
    double weight = 0;
    double value  = 0;

    // Try to find the next item with the most value that fits in the bag
    while (weight < (double)maxWeight) {
        // Local best item
        unsigned int bestItem      = -1;
        double       bestItemRatio = -1;

        // For every item
        for (unsigned int i = 0; i < n; i++) {
            // If already in the bag ignore
            if (usedItems[i]) continue;

            // If better value than current best item, replace it
            double ratio = (double)values[i] / weights[i];
            if (ratio > bestItemRatio) {
                bestItem      = i;
                bestItemRatio = ratio;
            }
        }


        // Calculate fraction of item to use
        double weightLeft = maxWeight - weight;
        double fraction   = weightLeft / weights[bestItem];
        fraction          = std::min(fraction, (double)1);

        // Mark it as used
        usedItems[bestItem] = fraction;

        // Increase weight and value sum
        weight += weights[bestItem] * fraction;
        value  += values[bestItem] * fraction;
    }

    return value;
}
