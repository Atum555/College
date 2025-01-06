package com.ldts.up202306618.elements.complex;

import com.ldts.up202306618.area.SumProvider;

import java.util.ArrayList;
import java.util.List;

public class City implements SumProvider {
    private final List<House> houses;

    public City() {
        this.houses = new ArrayList<>();
    }

    public void addHouse(House house) {
        this.houses.add(house);
    }

    @Override
    public double sum() {
        double sum = 0;
        for (House house : this.houses) sum += house.getArea();
        return sum;
    }
}
