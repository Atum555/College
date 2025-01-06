package com.ldts.up202306618.drinks;

public class StringReplacer implements StringTransformer {
    private final char a;
    private final char b;

    public StringReplacer(char a, char b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public void execute(StringDrink drink) {
        String original = drink.getText();
        StringBuilder builder = new StringBuilder();

        for (char c : original.toCharArray()) {
            if (c == this.a) builder.append(this.b);
            else builder.append(c);
        }

        drink.setText(builder.toString());
    }

    @Override
    public void undo(StringDrink drink) {
        String original = drink.getText();
        StringBuilder builder = new StringBuilder();

        for (char c : original.toCharArray()) {
            if (c == this.b) builder.append(this.a);
            else builder.append(c);
        }

        drink.setText(builder.toString());
    }
}
