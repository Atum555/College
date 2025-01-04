package com.aor.numbers.filters;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DivisibleByFilterTest {
    @Test
    public void accept_1_1() {
        DivisibleByFilter filter = new DivisibleByFilter(1);
        Assertions.assertTrue(filter.accept(-10));
    }

    @Test
    public void accept_1_2() {
        DivisibleByFilter filter = new DivisibleByFilter(1);
        Assertions.assertTrue(filter.accept(-1));
    }

    @Test
    public void accept_1_3() {
        DivisibleByFilter filter = new DivisibleByFilter(1);
        Assertions.assertTrue(filter.accept(0));
    }

    @Test
    public void accept_1_4() {
        DivisibleByFilter filter = new DivisibleByFilter(1);
        Assertions.assertTrue(filter.accept(1));
    }

    @Test
    public void accept_1_5() {
        DivisibleByFilter filter = new DivisibleByFilter(1);
        Assertions.assertTrue(filter.accept(13));
    }

    @Test
    public void accept_2_1() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertTrue(filter.accept(-20));
    }

    @Test
    public void accept_2_2() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertFalse(filter.accept(-11));
    }

    @Test
    public void accept_2_3() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertTrue(filter.accept(-2));
    }

    @Test
    public void accept_2_4() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertFalse(filter.accept(-1));
    }

    @Test
    public void accept_2_5() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertTrue(filter.accept(0));
    }

    @Test
    public void accept_2_6() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertFalse(filter.accept(1));
    }

    @Test
    public void accept_2_7() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertTrue(filter.accept(2));
    }

    @Test
    public void accept_2_8() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertFalse(filter.accept(3));
    }

    @Test
    public void accept_2_9() {
        DivisibleByFilter filter = new DivisibleByFilter(2);
        Assertions.assertTrue(filter.accept(10));
    }
}
