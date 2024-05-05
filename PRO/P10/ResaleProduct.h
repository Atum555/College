#ifndef __ResaleProduct_h__
#define __ResaleProduct_h__

#include "Product.h"

class ResaleProduct : public Product {
  public:
    ResaleProduct(int id, float price, int margin)
        : Product(id, price), margin_(margin) {}

    int get_profit_margin() const { return margin_; }

    void set_profit_margin(int margin) { margin_ = margin; }

    float get_sell_price() const {
        return price_ * ((float(100 + margin_)) / 100);
    }

  protected:
    int margin_;
};

#endif