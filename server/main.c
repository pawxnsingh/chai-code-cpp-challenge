#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <asm-generic/socket.h>

#define PORT 8080
#define BACKLOG 10

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, BACKLOG) < 0) {
        perror("server failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    // Accept and handle incoming connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        // Read request
        read(new_socket, buffer, sizeof(buffer));
        printf("Received:\n%s\n", buffer);

        // Send response
        const char *response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 13\r\n"
            "\r\n"
            "Hello, World!";
        write(new_socket, response, strlen(response));

        // Close connection
        close(new_socket);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
