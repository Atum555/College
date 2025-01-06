package com.ldts.up202306618.elements.simple;

import com.ldts.up202306618.elements.AreaShape;

public class Triangle implements AreaShape {
    private final double baseSize;
    private final double height;

    public Triangle(double baseSize, double height) {
        this.baseSize = baseSize;
        this.height = height;
    }

    @Override
    public double getArea() {
        return (this.baseSize * this.height) / 2;
    }

    @Override
    public void draw() {
        System.out.println("Drawing Triangle.");
    }
}
