package com.aor.numbers.filters;

public class DivisibleByFilter implements GenericListFilter {
    private final int divisor;

    public DivisibleByFilter(int divisor) {
        this.divisor = divisor;
    }

    @Override
    public boolean accept(Integer number) {
        return number % this.divisor == 0;
    }
}
