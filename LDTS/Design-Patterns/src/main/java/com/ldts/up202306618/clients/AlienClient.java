package com.ldts.up202306618.clients;

import com.ldts.up202306618.bars.Bar;
import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.clients.orders.OrderingStrategy;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public abstract class AlienClient implements Client {
    private final OrderingStrategy strategy;

    public AlienClient() {
        this.strategy = this.createOrderingStrategy();
    }

    protected abstract OrderingStrategy createOrderingStrategy();

    @Override
    public void happyHourStarted(Bar bar) {
        this.strategy.happyHourStarted(bar);
    }

    @Override
    public void happyHourEnded(Bar bar) {
        this.strategy.happyHourEnded(bar);
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        this.strategy.wants(drink, recipe, bar);
    }
}
