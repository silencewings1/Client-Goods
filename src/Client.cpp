#include "Client.h"

Client::Client(double discount)
    : discount(discount)
{
}

const Client& Client::getGoldCardMember()
{
    static Client client(0.9);
    return client;
}

const Client& Client::getSliverCardMember()
{
    static Client client(0.95);
    return client;
}

const Client& Client::getNotMember()
{
    static Client client(1.0);
    return client;
}

double Client::getDiscount() const
{
    return discount;
}