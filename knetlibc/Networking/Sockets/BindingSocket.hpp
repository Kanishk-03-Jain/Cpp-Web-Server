// BindingSocket.hpp
//
// This class implements a call to the bind() function of sockets as a definition of the connect_to_network virtual function from SimpleSocket

#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace KNET
{
    class BindingSocket: public SimpleSocket 
    {
        public:
            // Constructor 
            BindingSocket(int domain, int service, int protocol, int port, u_long interface);

            // Virtual fuction from parent
            int connect_to_network(int sock, struct sockaddr_in address);

    };
}

#endif /* BindingSocket_hpp*/