#include "GoodsImpl.h"

GoodsImpl::GoodsImpl(float price, bool is_onsale)
    : price{price}, is_onsale{is_onsale}
{
}

float GoodsImpl::getPrice() const
{
    return price;
}

bool GoodsImpl::isOnSale() const
{
    return is_onsale;
}