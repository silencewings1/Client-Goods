#include "Exercise.h"
#include <iostream>

int main()
{
	auto client1 = __client(MemberLevel::GOLD_CARD); 
	client1->addGoods(Items::NESTLE_COFFEE, 4);
	client1->addGoods(Items::COFFEE_CUP);
	client1->addGoods(Items::FRUIT_TEA, 2);

	std::cout << client1->totalPrice() << std::endl;

	return 0;
}