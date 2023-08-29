# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <sys/socket.h>
# include <stdio.h>
# include <netinet/in.h>

namespace sck {
class ConcreteSocketCreation {
   public:
      ConcreteSocketCreation(int domain, int service, int protocol, int port, u_long interface);
      virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
      void testConnection(int);
      int getSocket();
      int getConnection();
	  void	setConnection(int con);
      struct sockaddr_in getAddress();
   private:
      struct sockaddr_in address;
      int sockt;
      int connection;
};
 
}