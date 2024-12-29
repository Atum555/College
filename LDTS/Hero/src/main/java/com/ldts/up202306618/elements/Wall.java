package com.ldts.up202306618.elements;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.ldts.up202306618.utils.Position;

public class Wall extends Element {

    public Wall(Position position) {
        super(position);
    }

    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.setForegroundColor(TextColor.Factory.fromString("#000033"));
        graphics.putString(
                this.getPosition().getX(),
                this.getPosition().getY(),
                "X"
        );
    }
}
