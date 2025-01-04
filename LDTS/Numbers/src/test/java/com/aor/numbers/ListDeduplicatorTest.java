package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class ListDeduplicatorTest {
    private GenericListSorter listSorter;

    @BeforeEach
    public void setListSorter() {
        this.listSorter = Mockito.mock(GenericListSorter.class);
    }

    @Test
    public void deduplicate() {
        List<Integer> list = Arrays.asList(1, 2, 4, 2, 5);
        List<Integer> expected = Arrays.asList(1, 2, 4, 5);

        Mockito.when(this.listSorter.sort(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 2, 4, 5));
        ListDeduplicator deduplicator = new ListDeduplicator(this.listSorter);

        List<Integer> distinct = deduplicator.deduplicate(list);

        Assertions.assertEquals(expected, distinct);
    }

    @Test
    public void deduplicate_bug_8726() {
        List<Integer> list = Arrays.asList(1, 2, 4, 2);
        List<Integer> expected = Arrays.asList(1, 2, 4);

        Mockito.when(this.listSorter.sort(Mockito.anyList())).thenReturn(Arrays.asList(1, 2, 2, 4));
        ListDeduplicator deduplicator = new ListDeduplicator(this.listSorter);

        List<Integer> distinct = deduplicator.deduplicate(list);

        Assertions.assertEquals(expected, distinct);
    }
}
