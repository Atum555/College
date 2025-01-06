package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.AreaShape;

public class Ellipse implements AreaShape {
    private final double xRadius;
    private final double yRadius;

    public Ellipse(double xRadius, double yRadius) {
        this.xRadius = xRadius;
        this.yRadius = yRadius;
    }

    @Override
    public double getArea() {
        return Math.PI * this.xRadius * this.yRadius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Ellipse.");
    }
}
