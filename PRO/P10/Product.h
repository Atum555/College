#ifndef __Product_h__
#define __Product_h__

class Product {
  public:
    Product(int id, float price) : id_(id), price_(price) {};

    int get_id() const { return id_; }

    virtual float get_sell_price() const { return price_; }

  protected:
    int   id_;
    float price_;
};

#endif
