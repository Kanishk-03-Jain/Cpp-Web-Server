#include "TestServer.hpp"

KNET::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

void KNET::TestServer::acceptor()
{
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (sockaddr *)& address, (socklen_t *)&addrlen);

    read(new_socket, buffer, 30000);
}

void KNET::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void KNET::TestServer::responder() 
{
    char *hello = "Hello from server";
    write(new_socket, buffer, 30000);
    close(new_socket);
}

void KNET::TestServer::launch() 
{
    while (true) 
    {
        std::cout << "===== Waiting ======" << std::endl;
        acceptor();
        handler();
        responder();
        std::cout << "===== Done ======" << std::endl;
    }
}