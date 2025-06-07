#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>

class TcpHTTPServer {
  public:
    TcpHTTPServer(std::string ip_address, int port); // Constructor
    // ~TcpServer(); // Destructor
  private:
    int server_port;
    int server_ip_address;
    int server_socket;

    void startListening();

}