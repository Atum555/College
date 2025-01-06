package com.ldts.up202306618.elements.complex;

import com.ldts.up202306618.area.AreaAggregator;
import com.ldts.up202306618.elements.AreaShape;
import com.ldts.up202306618.elements.HasArea;

import java.util.ArrayList;
import java.util.List;

public class House implements HasArea {
    private final List<AreaShape> elements;

    public House() {
        this.elements = new ArrayList<>();
    }

    public void addElement(AreaShape element) {
        this.elements.add(element);
    }

    @Override
    public double getArea() {
        AreaAggregator aggregator = new AreaAggregator();
        for (AreaShape element : this.elements) aggregator.addElement(element);
        return aggregator.sum();
    }
}
