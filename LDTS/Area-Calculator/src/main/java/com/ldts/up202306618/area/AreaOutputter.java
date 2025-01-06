package com.ldts.up202306618.area;

public abstract class AreaOutputter {
    protected final SumProvider sumProvider;

    public AreaOutputter(SumProvider sumProvider) {
        this.sumProvider = sumProvider;
    }

    public abstract String output();
}
