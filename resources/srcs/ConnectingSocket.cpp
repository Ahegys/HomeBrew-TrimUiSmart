#include "ConnectingSocket.hpp"

sck::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : 
ConcreteSocketCreation(domain, service, protocol, port, interface) {
	setConnection(connect_to_network(getSocket(), getAddress()));
	testConnection(getConnection());
}

int sck::ConnectingSocket::connect_to_network(int sock, sockaddr_in address) {

	return connect(sock, (const struct sockaddr *)&address, sizeof(address));;
}
