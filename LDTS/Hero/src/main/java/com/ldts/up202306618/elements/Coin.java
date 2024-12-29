package com.ldts.up202306618.elements;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.ldts.up202306618.utils.Position;

public class Coin extends Element {
    public Coin(Position position) {
        super(position);
    }

    @Override
    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.setForegroundColor(TextColor.Factory.fromString("#DDDD33"));
        graphics.putString(
                this.getPosition().getX(),
                this.getPosition().getY(),
                "C"
        );
    }
}
