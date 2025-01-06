package com.ldts.up202306618.clients.orders;

import com.ldts.up202306618.bars.Bar;
import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public interface OrderingStrategy {
    void wants(StringDrink drink, StringRecipe recipe, StringBar bar);

    void happyHourStarted(Bar bar);

    void happyHourEnded(Bar bar);
}
