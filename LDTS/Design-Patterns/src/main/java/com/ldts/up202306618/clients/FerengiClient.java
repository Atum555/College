package com.ldts.up202306618.clients;

import com.ldts.up202306618.clients.orders.OrderingStrategy;
import com.ldts.up202306618.clients.orders.SmartStrategy;

public class FerengiClient extends AlienClient{
    @Override
    protected OrderingStrategy createOrderingStrategy() {
        return new SmartStrategy();
    }
}
