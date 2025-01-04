package com.aor.numbers.filters;

import java.util.ArrayList;
import java.util.List;

public class ListFilterer {
    private final GenericListFilter filter;

    public ListFilterer(GenericListFilter filter) {
        this.filter = filter;
    }

    public List<Integer> filter(List<Integer> list) {
        List<Integer> filteredList = new ArrayList<>();

        for (Integer number : list)
            if (this.filter.accept(number)) filteredList.add(number);

        return filteredList;
    }
}
