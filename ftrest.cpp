#include <iostream>
#include <string.h>
#include <sys/socket.h>
//#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <regex>

#include "common/box.cpp"
#include "common/message.cpp"
#include "common/socket.cpp"
#include "common/commands.cpp"

#define BUFSIZE 4096
using namespace std;

int main (int argc, const char * argv[]) {
    argumentBox box(argc, argv);
    int client_socket = createClientSocket(box.host.c_str(), box.port);
    
    if (box.command == "put")
        putRequest(&box, BUFSIZE, client_socket);
    else if (box.command == "mkd")
        mkdRequest(&box, BUFSIZE, client_socket);
    else if (box.command == "get")
        getRequest(&box, BUFSIZE, client_socket);
    else if (box.command == "lst")
        lstRequest(&box, BUFSIZE, client_socket);
    else if (box.command == "del")
        delRequest(&box, BUFSIZE, client_socket);
    else if (box.command == "rmd")
        rmdRequest(&box, BUFSIZE, client_socket);
    else
        exit(1);//todo error
    
    close(client_socket);
    return 0;
}
