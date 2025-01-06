package com.ldts.up202306618.drinks;

public interface StringTransformer {
    void execute(StringDrink drink);

    void undo(StringDrink drink);
}
