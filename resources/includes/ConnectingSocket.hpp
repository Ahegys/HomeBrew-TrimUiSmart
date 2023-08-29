#pragma once

# include "../includes/Bind.hpp"

namespace sck{
	class ConnectingSocket : public ConcreteSocketCreation {
		public:
			ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
		int connect_to_network(int sock, struct sockaddr_in address);
	};
}