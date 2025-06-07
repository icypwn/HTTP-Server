#include "http_server.h"

TcpHTTPServer::TcpHTTPServer(string ip_address, int port) {

  // Set class variables 
  server_ip_address = ip_address;
  server_port = port;

  // Create a server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0); // Domain (IPv4), Type of Socket (TCP), Protocol (0 = Default)

  // Define the server address for the server socket
  sockaddr_in server_address; // Defines the server address class
  server_address.sin_family = AF_INET; // Family
  server_address.sin_port = htons(8080); // htons() converts unsigned ints into network byte order
  server_address.sin_addr.s_addr = inet_addr(server_ip_address.c_str()); // Sets an IP for the socket

  // Bind the server socket using the server_socket and server_address as parameters
  // This assigns the local address (IP & Port) we specified to the server socket so we can listen on it
  bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

  // Start listening on the server socket

  log("TCP Socket successfully opened");

  startListening(5);

}

// Waits for requests to comes in and puts them into a queue
void TcpHTTPServer::startListening(int limit) {
  listen(server_socket, limit);
  cout << "Listening to " << server_ip_address << " on port " << server_port << endl;
}

void TcpHTTPServer::log(string message) {
  cout << message << endl;
}

// Recieves the most recent message from the queue
void TcpHTTPServer::recieve() {

  // Exract the first connection on the queue (Will empty page if it's empty)
  client_socket = accept(server_socket, nullptr, nullptr);

  // Recieve data from the client in a buffer
  char client_data[1024] = {0};
  recv(client_socket, client_data, sizeof(client_data), 0); // Recieves the data from this socket

  cout << "Message from client: " << client_data << endl;

  // Close the socket
  shutdown(server_socket, SHUT_RDWR);
  
}