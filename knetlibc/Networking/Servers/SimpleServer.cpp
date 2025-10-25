// SimpeServer.cpp

#include "SimpleServer.hpp"

KNET::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

KNET::ListeningSocket* KNET::SimpleServer::get_socket()
{
    return socket;
}