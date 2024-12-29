package com.ldts.up202306618.elements;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.ldts.up202306618.utils.Position;

public class Monster extends Element {
    public Monster(Position position) {
        super(position);
    }

    @Override
    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.setForegroundColor(TextColor.Factory.fromString("#FF6633"));
        graphics.putString(
                this.getPosition().getX(),
                this.getPosition().getY(),
                "M"
        );
    }
}
