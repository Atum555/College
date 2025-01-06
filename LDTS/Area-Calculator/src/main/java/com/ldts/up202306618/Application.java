package com.ldts.up202306618;

import com.ldts.up202306618.area.AreaAggregator;
import com.ldts.up202306618.area.AreaOutputter;
import com.ldts.up202306618.area.AreaStringOutputter;
import com.ldts.up202306618.area.AreaXMLOutputter;
import com.ldts.up202306618.elements.complex.City;
import com.ldts.up202306618.elements.complex.House;
import com.ldts.up202306618.elements.simple.*;

public class Application {
    public static void main(String[] args) {
        // Create AreaAggregator and Outputters
        AreaAggregator aggregator = new AreaAggregator();
        AreaOutputter outputter1 = new AreaStringOutputter(aggregator);
        AreaOutputter outputter2 = new AreaXMLOutputter(aggregator);

        // Add Elements
        aggregator.addElement(new Circle(3));
        aggregator.addElement(new Circle(5));
        aggregator.addElement(new Square(3));
        aggregator.addElement(new Square(7));
        aggregator.addElement(new Ellipse(1, 2));
        aggregator.addElement(new Rectangle(3, 4));
        aggregator.addElement(new Triangle(5, 6));

        // Print Area
        System.out.println("Before House");
        System.out.println(outputter1.output());
        System.out.println(outputter2.output());

        // Add House
        House house = new House();
        house.addElement(new Triangle(2, 4));
        house.addElement(new Square(4));
        house.addElement(new Rectangle(7, 2));
        aggregator.addElement(house);

        // Print new Area
        System.out.println("After House");
        System.out.println(outputter1.output());
        System.out.println(outputter2.output());

        // Create City
        City city = new City();
        outputter1 = new AreaStringOutputter(city);
        outputter2 = new AreaXMLOutputter(city);

        // Add houses
        house = new House();
        house.addElement(new Triangle(2, 4));
        house.addElement(new Square(4));
        house.addElement(new Rectangle(7, 2));
        city.addHouse(house);

        house = new House();
        house.addElement(new Triangle(2, 4));
        house.addElement(new Square(4));
        house.addElement(new Rectangle(7, 2));
        city.addHouse(house);

        house = new House();
        house.addElement(new Triangle(2, 4));
        house.addElement(new Square(4));
        house.addElement(new Rectangle(7, 2));
        city.addHouse(house);

        // Print city area
        System.out.println("City");
        System.out.println(outputter1.output());
        System.out.println(outputter2.output());

    }
}
