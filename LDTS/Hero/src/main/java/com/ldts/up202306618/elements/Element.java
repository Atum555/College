package com.ldts.up202306618.elements;

import com.googlecode.lanterna.graphics.TextGraphics;
import com.ldts.up202306618.utils.Position;

public abstract class Element {
    private Position position;

    public Element(Position position) {
        this.position = position;
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public abstract void draw(TextGraphics graphics);
}
