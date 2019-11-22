#include "gtest/gtest.h"
#include "Exercise.h"

// HELPER
void addSomeGoods(std::unique_ptr<Client> &client)
{
    client->addGoods(Items::NESTLE_COFFEE, 9);
    client->addGoods(Items::COFFEE_CUP);
    client->addGoods(Items::FRUIT_TEA, 5);
    client->addGoods(Items::CHOCOLATE, 10);
}

void removeSomeGoods(std::unique_ptr<Client> &client)
{
    client->removeGoods(Items::NESTLE_COFFEE, 9);
    client->removeGoods(Items::COFFEE_CUP, 1);
    client->removeGoods(Items::FRUIT_TEA, 5);
    client->removeGoods(Items::CHOCOLATE, 10);
}

void removeAllGoods(std::unique_ptr<Client> &client)
{
    client->removeAll(Items::NESTLE_COFFEE);
    client->removeAll(Items::FRUIT_TEA);
}

// TEST GOLD_CARD
TEST(GOLD_CARD, test_ADD_and_ADD_MORE)
{
    auto client = __client(MemberLevel::GOLD_CARD);

    addSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 1456.2f);

    addSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 2912.4f);
}

TEST(GOLD_CARD, test_ADD_and_REMOVE_SOME)
{
    auto client = __client(MemberLevel::GOLD_CARD);

    addSomeGoods(client);
    addSomeGoods(client);
    removeSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 1456.2f);
}

TEST(GOLD_CARD, test_ADD_and_REMOVE_ALL)
{
    auto client = __client(MemberLevel::GOLD_CARD);

    addSomeGoods(client);
    addSomeGoods(client);
    removeAllGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 986.4f);
}

TEST(GOLD_CARD, test_ADD_and_EMPTY)
{
    auto client = __client(MemberLevel::GOLD_CARD);

    addSomeGoods(client);
    client->emptyShoppingCart();
    EXPECT_FLOAT_EQ(client->totalPrice(), 0.0f);
}

// TEST NON_MEMBER
TEST(NON_MEMBER, test_ADD_and_ADD_MORE)
{
    auto client = __client(MemberLevel::NON_MEMBER);

    addSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 1570.0f);

    addSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 3140.0f);
}

TEST(NON_MEMBER, test_ADD_and_REMOVE_SOME)
{
    auto client = __client(MemberLevel::NON_MEMBER);

    addSomeGoods(client);
    addSomeGoods(client);
    removeSomeGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 1570.0f);
}

TEST(NON_MEMBER, test_ADD_and_REMOVE_ALL)
{
    auto client = __client(MemberLevel::NON_MEMBER);

    addSomeGoods(client);
    addSomeGoods(client);
    removeAllGoods(client);
    EXPECT_FLOAT_EQ(client->totalPrice(), 1096.0f);
}

TEST(NON_MEMBER, test_ADD_and_EMPTY)
{
    auto client = __client(MemberLevel::NON_MEMBER);

    addSomeGoods(client);
    client->emptyShoppingCart();
    EXPECT_FLOAT_EQ(client->totalPrice(), 0.0f);
}