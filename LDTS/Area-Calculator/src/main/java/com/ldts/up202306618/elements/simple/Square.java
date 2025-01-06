package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.AreaShape;

public class Square implements AreaShape {
    private final double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double getArea() {
        return this.side * this.side;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Square.");
    }
}
