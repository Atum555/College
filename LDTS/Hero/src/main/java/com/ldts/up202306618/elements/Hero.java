package com.ldts.up202306618.elements;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.ldts.up202306618.utils.Position;

public class Hero extends Element {
    public Hero(Position position) {
        super(position);
    }

    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFFF33"));
        graphics.putString(
                this.getPosition().getX(),
                this.getPosition().getY(),
                "H"
        );
    }

    public Position moveUp() {
        return new Position(
                this.getPosition().getX(),
                this.getPosition().getY() - 1
        );
    }

    public Position moveDown() {
        return new Position(
                this.getPosition().getX(),
                this.getPosition().getY() + 1
        );
    }

    public Position moveLeft() {
        return new Position(
                this.getPosition().getX() - 1,
                this.getPosition().getY()
        );
    }

    public Position moveRight() {
        return new Position(
                this.getPosition().getX() + 1,
                this.getPosition().getY()
        );
    }
}
