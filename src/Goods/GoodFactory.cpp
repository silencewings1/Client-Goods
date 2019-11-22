#include "GoodsFactory.h"
#include "GoodsImpl.h"
#include "Items.h"

std::unique_ptr<Goods> GoodsFactory::create(const Items &item)
{
    float price = 0.0f;
    bool is_onsale = false;

    switch (item)
    {
    case Items::NESTLE_COFFEE:
        price = 48.0f;
        is_onsale = true;
        break;
    case Items::COFFEE_CUP:
        price = 60.0f;
        is_onsale = false;
        break;
    case Items::CHOCOLATE:
        price = 48.8f;
        is_onsale = false;
        break;
    case Items::FRUIT_TEA:
        price = 118.0f;
        is_onsale = false;
        break;
    }

    return std::unique_ptr<Goods>(new GoodsImpl(price, is_onsale));
}