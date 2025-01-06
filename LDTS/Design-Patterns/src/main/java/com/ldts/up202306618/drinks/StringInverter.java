package com.ldts.up202306618.drinks;

public class StringInverter implements StringTransformer {
    @Override
    public void execute(StringDrink drink) {
        String original = drink.getText();
        StringBuilder builder = new StringBuilder();

        for (int i = original.length() - 1; i >= 0; i--) builder.append(original.charAt(i));

        drink.setText(builder.toString());
    }

    @Override
    public void undo(StringDrink drink) {
        this.execute(drink);
    }
}
