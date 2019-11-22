#include "ClientImpl.h"
#include "Goods/GoodsFactory.h"
#include "Goods/Goods.h"

ClientImpl::ClientImpl(float discount)
    : discount{discount}
{
}

void ClientImpl::addGoods(const Items &item, int number)
{
    auto it = shopping_cart.find(item);
    if (it != shopping_cart.end()) // existed
    {
        shopping_cart.at(item) += number;
    }
    else
    {
        shopping_cart.insert(std::make_pair(item, number));
    }
}

void ClientImpl::removeAll(const Items &item)
{
    auto it = shopping_cart.find(item);
    if (it != shopping_cart.end()) // existed
    {
        shopping_cart.erase(it);
    }
    else
    {
        // error
    }
}

void ClientImpl::removeGoods(const Items &item, int number)
{
    auto it = shopping_cart.find(item);
    if (it != shopping_cart.end() && it->second >= number) 
    {
        shopping_cart.at(item) -= number;
    }
    else
    {
        // error
    }
}

void ClientImpl::emptyShoppingCart()
{
    shopping_cart.clear();
}

float ClientImpl::totalPrice() const
{
    float total_price = 0.0f;

    for (auto &elem : shopping_cart)
    {
        auto goods = GoodsFactory::create(elem.first);
        auto num = elem.second;

        total_price += num * goods->getPrice() * (goods->isOnSale() ? 1.0f : discount);
    }

    return total_price;
}
