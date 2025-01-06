package com.ldts.up202306618.clients;

import com.ldts.up202306618.bars.Bar;

public interface BarObserver {
    void happyHourStarted(Bar bar);

    void happyHourEnded(Bar bar);
}
