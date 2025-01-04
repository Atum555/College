package com.aor.numbers.filters;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PositiveFilterTest {
    @Test
    public void accept_1() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertFalse(filter.accept(0));
    }

    @Test
    public void accept_2() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertFalse(filter.accept(-1));
    }

    @Test
    public void accept_3() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertFalse(filter.accept(-2));
    }

    @Test
    public void accept_4() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertFalse(filter.accept(-23));
    }

    @Test
    public void accept_5() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertTrue(filter.accept(1));
    }

    @Test
    public void accept_6() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertTrue(filter.accept(2));
    }

    @Test
    public void accept_7() {
        PositiveFilter filter = new PositiveFilter();
        Assertions.assertTrue(filter.accept(32));
    }
}
