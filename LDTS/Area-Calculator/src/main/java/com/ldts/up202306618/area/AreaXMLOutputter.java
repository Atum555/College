package com.ldts.up202306618.area;

public class AreaXMLOutputter extends AreaOutputter {
    public AreaXMLOutputter(SumProvider sumProvider) {
        super(sumProvider);
    }

    @Override
    public String output() {
        return "<arena>" + this.sumProvider.sum() + "</arena>";
    }
}
