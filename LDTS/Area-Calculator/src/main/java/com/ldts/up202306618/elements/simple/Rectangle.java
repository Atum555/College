package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.AreaShape;

public class Rectangle implements AreaShape {
    private final double width;
    private final double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double getArea() {
        return this.height * this.width;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Rectangle.");
    }
}
