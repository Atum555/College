package com.ldts.up202306618.area;

import com.ldts.up202306618.elements.HasArea;

import java.util.ArrayList;
import java.util.List;

public class AreaAggregator implements SumProvider {
    private final List<HasArea> hasAreaObjects;

    public AreaAggregator() {
        this.hasAreaObjects = new ArrayList<>();
    }

    public void addElement(HasArea hasAreaObject) {
        this.hasAreaObjects.add(hasAreaObject);
    }

    public double sum() {
        double sum = 0;
        for (HasArea hasAreaObject : this.hasAreaObjects) sum += hasAreaObject.getArea();
        return sum;
    }
}
