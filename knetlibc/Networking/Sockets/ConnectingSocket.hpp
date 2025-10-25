// ConnectionSocket.hpp
//
// This class implements a call to the connect() function of sockets as the definition of connect_to_network virtual function from SimpleSocket

#ifndef ConnectionSocket_hpp
#define ConnectionSockt_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace KNET 
{
    class ConnectionSocket: public SimpleSocket 
    {
        public:
            // Constructor
            ConnectionSocket(int domain, int service, int protocol, int port, u_long interface);

            // Virtual fuction from parent
            int connect_to_network(int sock, struct sockaddr_in address);
    };
}


#endif /* ConnectingSocket_hpp */