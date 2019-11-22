#pragma once

enum class Items;

class Client
{
public:
	virtual ~Client() = default;

	virtual void addGoods(const Items& item, int number = 1) = 0;
	virtual void removeAll(const Items& item) = 0;
	virtual void removeGoods(const Items& item, int number) = 0;
	virtual void emptyShoppingCart() = 0;

	virtual float totalPrice() const = 0;
};