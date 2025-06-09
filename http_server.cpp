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
int TcpHTTPServer::recieve() {

  // Exract the first connection on the queue (Will empty page if it's empty)
  client_socket = accept(server_socket, nullptr, nullptr);

  // Recieve data from the client in a buffer
  char client_data[1024] = {0};
  if(recv(client_socket, client_data, sizeof(client_data), 0)) {
    cout << "Message from client: " << endl << client_data;
    return 1;
  }
  else {
    cout << "No data recieved yet." << endl;
    return 0;
  }
  
}

void TcpHTTPServer::respond(int status_code) {
  // Send data back to the client in a buffer
  if(status_code == 200) {
  char server_response[1024] = " HTTP/1.1 200 OK Content-Type: text/plain Content-length: 2 OK";
  send(server_socket, server_response, sizeof(server_response), 0);
  }
  else {
    cout << "Unknown Response: (Code " << status_code << ")" << endl;
  }

}