#pragma once
#include <memory>

class Goods;
enum class Items;

class GoodsFactory
{
public:
	GoodsFactory() = delete;
	static std::unique_ptr<Goods> create(const Items &item);
};
