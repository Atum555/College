package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.AreaShape;

public class Circle implements AreaShape {
    private final double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Circle.");
    }
}
