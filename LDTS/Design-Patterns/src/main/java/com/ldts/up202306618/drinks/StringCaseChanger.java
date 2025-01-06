package com.ldts.up202306618.drinks;

public class StringCaseChanger implements StringTransformer {
    @Override
    public void execute(StringDrink drink) {
        String original = drink.getText();
        StringBuilder builder = new StringBuilder();

        for (char c : original.toCharArray()) {
            if (Character.isLowerCase(c)) builder.append(Character.toUpperCase(c));
            else builder.append(Character.toLowerCase(c));
        }

        drink.setText(builder.toString());
    }

    @Override
    public void undo(StringDrink drink) {
        this.execute(drink);
    }
}
