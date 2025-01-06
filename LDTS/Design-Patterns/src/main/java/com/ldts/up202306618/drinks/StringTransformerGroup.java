package com.ldts.up202306618.drinks;

import java.util.List;

public class StringTransformerGroup implements StringTransformer {
    private final List<StringTransformer> transformers;

    public StringTransformerGroup(List<StringTransformer> transformers) {
        this.transformers = transformers;
    }

    public void execute(StringDrink drink) {
        for (StringTransformer transformer : this.transformers) transformer.execute(drink);
    }

    @Override
    public void undo(StringDrink drink) {
        for (StringTransformer transformer : this.transformers) transformer.undo(drink);
    }
}
