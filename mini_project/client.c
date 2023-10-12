#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8083);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    // Get client type from the user
    char client_type;
    printf("Enter client type (A for Admin, S for Student, F for Faculty): ");
    scanf(" %c", &client_type);

    // Send the client type to the server
    send(client_socket, &client_type, sizeof(client_type), 0);

    // Handle the specific client logic
    // For simplicity, we'll just print the message received from the server
    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("Error in receiving");
        exit(EXIT_FAILURE);
    }

    printf("Message from server: %.*s\n", bytes_received, buffer);

    // Close the socket
    close(client_socket);

    return 0;
}