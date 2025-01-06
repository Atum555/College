package com.ldts.up202306618.clients;

import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public interface Client extends BarObserver {
    void wants(StringDrink drink, StringRecipe recipe, StringBar bar);
}
