#pragma once
#include "Goods.h"

class GoodsImpl : public Goods
{
public:
    GoodsImpl(float price, bool is_onsale);

    float getPrice() const override;
    bool isOnSale() const override;

private:
    float price;
    bool is_onsale;
};