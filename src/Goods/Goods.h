#pragma once

class Goods
{
public:
	virtual ~Goods() = default;

	virtual float getPrice() const = 0;
	virtual bool isOnSale() const = 0;
};