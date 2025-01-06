package com.ldts.up202306618.clients;

import com.ldts.up202306618.clients.orders.ImpatientStrategy;
import com.ldts.up202306618.clients.orders.OrderingStrategy;

public class RomulanClient extends AlienClient {
    @Override
    protected OrderingStrategy createOrderingStrategy() {
        return new ImpatientStrategy();
    }
}
