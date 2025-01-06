package com.ldts.up202306618.bars;

import com.ldts.up202306618.clients.BarObserver;

import java.util.ArrayList;
import java.util.List;

public abstract class Bar {
    private final List<BarObserver> observers;

    public Bar() {
        this.observers = new ArrayList<>();
    }

    public void addObserver(BarObserver observer) {
        this.observers.add(observer);
    }

    public void removeObserver(BarObserver observer) {
        this.observers.remove(observer);
    }

    public void notifyObservers() {
        for (BarObserver observer : this.observers)
            if (this.isHappyHour()) observer.happyHourStarted(this);
            else observer.happyHourEnded(this);
    }

    abstract public boolean isHappyHour();

    abstract public void startHappyHour();

    abstract public void endHappyHour();
}
