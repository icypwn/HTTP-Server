#include "http_server.h"

#include <stdio.h>

// HTTP Web Server that uses TCP

int main() {

// Instantiate web server class
TcpHTTPServer server1 = TcpHTTPServer("127.0.0.1", 8080);

return 0;

}