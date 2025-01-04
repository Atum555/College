package com.aor.numbers.filters;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class ListFiltererTest {
    @Test
    public void filter() {
        List<Integer> list = Arrays.asList(-4, -3, 0, 2, 7);
        List<Integer> expected = Arrays.asList(-3, 2, 7);

        GenericListFilter filter = Mockito.mock(GenericListFilter.class);
        Mockito.when(filter.accept(-1)).thenReturn(false);
        Mockito.when(filter.accept(-3)).thenReturn(true);
        Mockito.when(filter.accept(0)).thenReturn(false);
        Mockito.when(filter.accept(2)).thenReturn(true);
        Mockito.when(filter.accept(7)).thenReturn(true);

        ListFilterer filterer = new ListFilterer(filter);
        List<Integer> result = filterer.filter(list);

        Assertions.assertEquals(expected, result);
    }
}
