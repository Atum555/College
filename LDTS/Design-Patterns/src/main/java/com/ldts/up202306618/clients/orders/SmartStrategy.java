package com.ldts.up202306618.clients.orders;

import com.ldts.up202306618.bars.Bar;
import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

import java.util.ArrayList;
import java.util.List;

public class SmartStrategy implements OrderingStrategy {
    private final List<StringOrder> stringOrders;

    public SmartStrategy() {
        this.stringOrders = new ArrayList<>();
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        if (bar.isHappyHour()) bar.order(drink, recipe);
        else this.stringOrders.add(new StringOrder(drink, recipe, bar));
    }

    @Override
    public void happyHourStarted(Bar bar) {
        for (StringOrder order : this.stringOrders) {
            if (order.bar().equals(bar)) {
                order.bar().order(order.drink(), order.recipe());
                break;
            }
        }
    }

    @Override
    public void happyHourEnded(Bar bar) {
    }
}
