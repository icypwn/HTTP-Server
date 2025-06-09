#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

class TcpHTTPServer {
  public:
    TcpHTTPServer(string ip_address, int port); // Constructor
    void startListening(int limit);
    int recieve();
    void respond(int status_code);
    
    // ~TcpServer(); // Destructor
  private:
    int server_port;
    string server_ip_address;
    int server_socket;
    int client_socket;

    void log(string message);

};