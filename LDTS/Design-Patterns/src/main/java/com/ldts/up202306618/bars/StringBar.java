package com.ldts.up202306618.bars;

import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public class StringBar extends Bar {
    private boolean happy;

    public StringBar() {
        this.happy = false;
    }

    public void order(StringDrink drink, StringRecipe recipe) {
        recipe.mix(drink);
    }

    @Override
    public boolean isHappyHour() {
        return this.happy;
    }

    @Override
    public void startHappyHour() {
        this.happy = true;
        this.notifyObservers();
    }

    @Override
    public void endHappyHour() {
        this.happy = false;
        this.notifyObservers();
    }
}
