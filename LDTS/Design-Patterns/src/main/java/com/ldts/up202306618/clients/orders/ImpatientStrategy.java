package com.ldts.up202306618.clients.orders;

import com.ldts.up202306618.bars.Bar;
import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public class ImpatientStrategy implements OrderingStrategy {
    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        bar.order(drink, recipe);
    }

    @Override
    public void happyHourStarted(Bar bar) {
    }

    @Override
    public void happyHourEnded(Bar bar) {
    }
}
