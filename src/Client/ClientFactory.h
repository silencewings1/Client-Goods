#pragma once
#include <memory>

class Client;
enum class MemberLevel;

class ClientFactory
{
public:
	ClientFactory() = delete;
	static std::unique_ptr<Client> create(const MemberLevel& level);
};

#define __client(...) ClientFactory::create(__VA_ARGS__)