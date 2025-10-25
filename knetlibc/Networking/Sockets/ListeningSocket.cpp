// ListeningSocket.cpp

#include "ListeningSocket.hpp"

// Constructor
KNET::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg): BindingSocket(domain, service, protocol, port, interface)
{
    backlog = bklg;
    start_listening();
    test_connection(listening);
}

// listening function
void KNET::ListeningSocket::start_listening()
{
    listening = listen(get_sock(), backlog);
}