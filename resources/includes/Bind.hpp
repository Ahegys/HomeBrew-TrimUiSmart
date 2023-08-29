#pragma once
#include "./Socket.hpp"

namespace sck {
class BindingSocket : public ConcreteSocketCreation {
	public:
		BindingSocket(int domain, int service, int protocol, int port, u_long interface);
		int connect_to_network(int sock, struct sockaddr_in address);
	};
}
