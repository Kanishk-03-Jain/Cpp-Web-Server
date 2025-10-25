#include "SimpleSocket.hpp"

// Default constructor

KNET::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface) 
{
    // Define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Establish Socket
    sock = socket(domain, service, protocol);
    test_connection(sock);
}

// Test connection virtual function

void KNET::SimpleSocket::test_connection(int item_to_test) 
{
    // Confirm that the socket or connection has been properly established
    if (item_to_test < 0) 
    {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}

// Getter Functions

struct sockaddr_in KNET::SimpleSocket::get_address()
{
    return address;
}

int KNET::SimpleSocket::get_connection() 
{
    return connection;
}

// Setter Functions

void KNET::SimpleSocket::set_connection(int conc)
{
    connection = conc;
}