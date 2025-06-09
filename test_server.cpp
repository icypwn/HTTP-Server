#include "http_server.h"

#include <stdlib.h>

// Just for sleeping/pausing
#include <thread>
#include <chrono>

// HTTP Web Server that uses TCP

int main() {

// Instantiate web server class (opens TCP socket)
TcpHTTPServer server1 = TcpHTTPServer("127.0.0.1", 8080);

// Starts to listen with a queue of 5
server1.startListening(5);

while(true) {
// If we successfully recieved a request
  if(server1.recieve()) {
    // Sends HTTP response to the sender
    server1.respond(200);
  }
  this_thread::sleep_for(chrono::seconds(3));
}

return 0;

}