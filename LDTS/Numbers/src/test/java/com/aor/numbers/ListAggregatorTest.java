package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListAggregatorTest {
    private GenericListDeduplicator deduplicator;

    @BeforeEach
    public void setListSorter() {
        this.deduplicator = Mockito.mock(GenericListDeduplicator.class);
    }

    private List<Integer> getTestList() {
        return Arrays.asList(1, 2, 4, 2, 5);
    }

    @Test
    public void sum() {
        List<Integer> list = this.getTestList();

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int sum = aggregator.sum(list);

        Assertions.assertEquals(14, sum);
    }

    @Test
    public void max() {
        List<Integer> list = this.getTestList();

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int max = aggregator.max(list);

        Assertions.assertEquals(5, max);
    }

    @Test
    public void max_2() {
        List<Integer> list = new ArrayList<>();

        ListAggregator aggregator = new ListAggregator(this.deduplicator);

        RuntimeException exception = Assertions.assertThrows(RuntimeException.class, () -> aggregator.max(list));
        Assertions.assertEquals("Empty List", exception.getMessage());
    }

    @Test
    public void max_bug_7263() {
        List<Integer> list = Arrays.asList(-1, -4, -5);

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int min = aggregator.max(list);

        Assertions.assertEquals(-1, min);
    }

    @Test
    public void min() {
        List<Integer> list = this.getTestList();

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int min = aggregator.min(list);

        Assertions.assertEquals(1, min);
    }

    @Test
    public void min_2() {
        List<Integer> list = Arrays.asList(2, 3, 1, 4);

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int min = aggregator.min(list);

        Assertions.assertEquals(1, min);
    }

    @Test
    public void min_3() {
        List<Integer> list = new ArrayList<>();

        ListAggregator aggregator = new ListAggregator(this.deduplicator);

        RuntimeException exception = Assertions.assertThrows(RuntimeException.class, () -> aggregator.min(list));
        Assertions.assertEquals("Empty List", exception.getMessage());
    }

    @Test
    public void distinct() {
        List<Integer> list = this.getTestList();

        Mockito.when(this.deduplicator.deduplicate(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 4, 5));

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int distinct = aggregator.distinct(list);

        Assertions.assertEquals(4, distinct);
    }

    @Test
    public void distinct_bug_8726() {
        List<Integer> list = Arrays.asList(1, 2, 4, 2);

        Mockito.when(this.deduplicator.deduplicate(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 4));

        ListAggregator aggregator = new ListAggregator(this.deduplicator);
        int distinct = aggregator.distinct(list);

        Assertions.assertEquals(3, distinct);
    }
}
