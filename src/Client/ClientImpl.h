#pragma once
#include "Client.h"
#include <unordered_map>

class ClientImpl : public Client
{
public:
	ClientImpl(float discount);

	void addGoods(const Items &item, int number) override;
	void removeAll(const Items &item) override;
	void removeGoods(const Items &item, int number) override;
	void emptyShoppingCart() override;

	float totalPrice() const override;

private:
	std::unordered_map<Items, int> shopping_cart;
	float discount;
};
