package com.ldts.up202306618.drinks;

import java.util.List;

public class StringRecipe {
    private final List<StringTransformer> transformers;

    public StringRecipe(List<StringTransformer> transformers) {
        this.transformers = transformers;
    }

    public void mix(StringDrink drink) {
        for (StringTransformer transformer : this.transformers) transformer.execute(drink);
    }
}
