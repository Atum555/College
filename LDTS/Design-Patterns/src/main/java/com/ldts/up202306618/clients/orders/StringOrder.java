package com.ldts.up202306618.clients.orders;

import com.ldts.up202306618.bars.StringBar;
import com.ldts.up202306618.drinks.StringDrink;
import com.ldts.up202306618.drinks.StringRecipe;

public record StringOrder(StringDrink drink, StringRecipe recipe, StringBar bar) {
}
