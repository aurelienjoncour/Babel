// Server-side Synchronous Chatting Application
// using C++ asio

#include "babel.hpp"
#include <iostream>
#include <algorithm>
#include <asio.hpp>
#include "BabelServer.hpp"

int main(UN int argc, UN char* argv[])
{
    try {
        auto serv = std::make_shared<Babel::BabelServer>();

        get_server(true, serv);
        serv->start();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}