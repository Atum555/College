package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.Shape;

public class Line implements Shape {
    private final double length;

    public Line(double length) {
        this.length = length;
    }

    public double getLength() {
        return length;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Line");
    }
}
