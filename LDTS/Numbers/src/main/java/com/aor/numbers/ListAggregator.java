package com.aor.numbers;

import java.util.List;

/**
 * A utility class that aggregates list of numbers
 * into a single integer using various functions.
 */
public class ListAggregator {
    private final GenericListDeduplicator deduplicator;

    public ListAggregator(GenericListDeduplicator deduplicator) {
        this.deduplicator = deduplicator;
    }

    /**
     * Sums all numbers in a list.
     *
     * @return The sum of all the values in the list.
     */
    public Integer sum(List<Integer> list) {
        int sum = 0;

        for (Integer number : list)
            sum += number;

        return sum;
    }

    /**
     * Calculates the maximum value in a list.
     *
     * @return The maximum value in the list.
     */
    public Integer max(List<Integer> list) {
        if (list.isEmpty()) throw new RuntimeException("Empty List");

        int max = list.getFirst();

        for (Integer number : list)
            if (number > max)
                max = number;

        return max;
    }

    /**
     * Calculates the minimum value in a list.
     *
     * @return The minimum value in the list.
     */
    public Integer min(List<Integer> list) {
        if (list.isEmpty()) throw new RuntimeException("Empty List");

        int min = list.getFirst();

        for (Integer number : list)
            if (number < min)
                min = number;

        return min;
    }

    /**
     * Counts the number of distinct numbers in a list.
     *
     * @return The number of distinct numbers.
     */
    public int distinct(List<Integer> list) {
        List<Integer> distinct = this.deduplicator.deduplicate(list);

        return distinct.size();
    }
}