#include <stdio.h>
// Operating system specific headers (Linux)
#include <sys/socket.h>


// HTTP web server written in C++
// This is a program that sits on a network and will respond to requests for web pages and other resources using HTTP

int main() {

//  * Task 1: Open a TCP socket on a port

// Create a server socket
int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // Domain (IPv4), Type of Socket (TCP), Protocol (0 = Default)

// Define the server address for the server socket
sockaddr_in serverAddress; // Define the server address class
serverAddress.sin_family = AF_INET; // Family
serverAddress.sin_port = htons(8080); // htons() converts unsigned ints into network byte order
serverAddress.sin_addr.s_addr = INADDR_ANY; // Used when we don't want to bind our socket to any particular IP and want it to listen to all IPs

// Bind the server socket using the serverSocket and serverAddress as parameters
// This assigns the local address (IP & Port) we specified to the server socket so we can listen on it
bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

// Start listening on the server socket
listen(serverSocket, 5);

// Exract the first connection on the queue
clientSocket = accept(serverSocket, nullptr, nullptr)

// Recieve data from the client in a buffer
char clientData[1024] = {0};
recv(clientSocket, buffer, sizeof(buffer), 0); // Recieves the data from this socket

std::cout << "Message from client: " << buffer << std::endl;

// Close the socket
close(serverSocket);

return 0;

}