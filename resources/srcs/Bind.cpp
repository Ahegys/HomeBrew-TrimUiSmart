#include "Bind.hpp"

sck::BindingSocket
::BindingSocket(int domain, int service, int protocol, int port, u_long interface) :
ConcreteSocketCreation::ConcreteSocketCreation(domain, service, protocol, port, interface)
{
	setConnection(connect_to_network(getSocket(), getAddress()));
	testConnection(getConnection());
}

int sck::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	return bind(sock, (const struct sockaddr *)&address, sizeof(address));
}
