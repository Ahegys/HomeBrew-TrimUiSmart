# include "../includes/Socket.hpp"

// yes, clean code :eyes:
sck::ConcreteSocketCreation
::ConcreteSocketCreation(int domain, int service, int protocol, int port, u_long interface) {
    // address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // establish socket
    sockt = socket(domain, service, protocol);
    testConnection(sockt);

}

struct sockaddr_in sck::ConcreteSocketCreation::getAddress() {
    return address;
}

int sck::ConcreteSocketCreation::getConnection() {
    return connection;
}

int sck::ConcreteSocketCreation::getSocket() {
    return sockt;
}


void sck::ConcreteSocketCreation::testConnection(int item_to_test) {
    if (item_to_test < 0) {
        perror("Failed to establish connection ...");
        exit(EXIT_FAILURE);
    }
}

void sck::ConcreteSocketCreation::setConnection(int con) {
	connection = con;
}