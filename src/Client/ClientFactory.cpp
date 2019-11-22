#include "ClientFactory.h"
#include "ClientImpl.h"
#include "MemberLevel.h"

std::unique_ptr<Client> ClientFactory::create(const MemberLevel &level)
{
    float discount = 0.0f;
    switch (level)
    {
    case MemberLevel::GOLD_CARD:
        discount = 0.9f;
        break;
    case MemberLevel::SILVER_CARD:
        discount = 0.95f;
        break;
    case MemberLevel::NON_MEMBER:
        discount = 1.0f;
        break;
    }

    return std::unique_ptr<Client>(new ClientImpl(discount));
}