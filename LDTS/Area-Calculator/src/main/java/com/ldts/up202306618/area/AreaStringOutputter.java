package com.ldts.up202306618.area;

public class AreaStringOutputter extends AreaOutputter {
    public AreaStringOutputter(SumProvider sumProvider) {
        super(sumProvider);
    }

    @Override
    public String output() {
        return "Sum of areas: " + this.sumProvider.sum();
    }
}
