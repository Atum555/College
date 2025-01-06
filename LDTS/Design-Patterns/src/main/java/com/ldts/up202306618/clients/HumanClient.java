package com.ldts.up202306618.clients;

import com.ldts.up202306618.bars.Bar;
import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.clients.orders.OrderingStrategy;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public class HumanClient implements Client {
    private final OrderingStrategy strategy;

    public HumanClient(OrderingStrategy strategy) {
        this.strategy = strategy;
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        this.strategy.wants(drink, recipe, bar);
    }

    @Override
    public void happyHourStarted(Bar bar) {
        this.strategy.happyHourStarted(bar);
    }

    @Override
    public void happyHourEnded(Bar bar) {
        this.strategy.happyHourEnded(bar);
    }
}
