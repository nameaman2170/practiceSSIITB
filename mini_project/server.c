#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "admin.h"
#include "student.h"
#include "faculty.h"


typedef struct {
    char username[20];
    char password[20];
} Credentials;

int authenticate_admin(const char *username, const char *password);
int authenticate_student(const char *username, const char *password);
int authenticate_faculty(const char *username, const char *password);
void handle_admin(int client_socket);
void handle_student(int client_socket);
void handle_faculty(int client_socket);

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8083);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 2) == -1) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8083\n");

    addr_len = sizeof(client_addr);

    // Get client type from the user
    char client_type;
    printf("Enter client type (A for Admin, S for Student, F for Faculty): ");
    scanf(" %c", &client_type);

    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);

        if (client_socket == -1) {
            perror("Error in accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected\n");

        // Determine client type and handle accordingly
        char username[20], password[20];
        int authenticated = 0;

        // Authenticate the client based on the client type
        switch (client_type) {
            case 'A':
                while (!authenticated) {
                    printf("Admin login\n");
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);
                    authenticated = authenticate_admin(username, password);
                }
                handle_admin(client_socket);
                break;
            case 'S':
                while (!authenticated) {
                    printf("Student login\n");
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);
                    authenticated = authenticate_student(username, password);
                }
                handle_student(client_socket);
                break;
            case 'F':
                while (!authenticated) {
                    printf("Faculty login\n");
                    printf("Enter username: ");
                    scanf("%s", username);
                    printf("Enter password: ");
                    scanf("%s", password);
                    authenticated = authenticate_faculty(username, password);
                }
                handle_faculty(client_socket);
                break;
            default:
                printf("Unknown client type\n");
                break;
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}

int authenticate_admin(const char *username, const char *password) {
    // Implement your admin authentication logic here
    // For simplicity, let's assume there's a single admin with a specific username and password
    return strcmp(username, "admin") == 0 && strcmp(password, "adminpassword") == 0;
}

int authenticate_student(const char *username, const char *password) {
    // Implement your student authentication logic here
    // For simplicity, let's assume there's a single student with a specific username and password
    return strcmp(username, "student") == 0 && strcmp(password, "studentpassword") == 0;
}

int authenticate_faculty(const char *username, const char *password) {
    // Implement your faculty authentication logic here
    // For simplicity, let's assume there's a single faculty with a specific username and password
    return strcmp(username, "faculty") == 0 && strcmp(password, "facultypassword") == 0;
}

void handle_admin(int client_socket) {
    // Handle admin logic here
    printf("Admin connected\n");

    // Example: Send a message to the admin
    const char *message = "Welcome, Admin!";
    send(client_socket, message, strlen(message), 0);
    int choice;
    while (1) {
        // Display the admin menu and get the choice
        choice = display_admin_menu();

        // Based on the choice, call the respective methods
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_faculty();
                break;
            case 3:
                activate_deactivate_student();
                break;
            case 4:
                update_student_faculty_details();
                break;
            case 5:
                printf("Exiting...\n");
                close(client_socket);
                // close(server_socket);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    //decide if we have to close connection or not
    //close(client_socket);
    //close(server_socket);
}

void handle_student(int client_socket) {
    // Handle student logic here
    printf("Student connected\n");

    // Example: Send a message to the student
    const char *message = "Welcome, Student!";
    send(client_socket, message, strlen(message), 0);

    int choice;
    while (1) {
        // Display the student menu and get the choice
        choice = display_student_menu();

        // Based on the choice, call the respective methods
        switch (choice) {
            case 1:
                enroll_courses();
                break;
            case 2:
                unenroll_courses();
                break;
            case 3:
                view_enrolled_courses();
                break;
            case 4:
                change_password();
                break;
            case 5:
                printf("Exiting...\n");
                close(client_socket);
                // close(server_socket);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    // decide if we have to close or not
    // close(client_socket);
    // close(server_socket);
}

void handle_faculty(int client_socket) {
    // Handle faculty logic here
    printf("Faculty connected\n");

    // Example: Send a message to the faculty
    const char *message = "Welcome, Faculty!";
    send(client_socket, message, strlen(message), 0);
    int choice;
    while (1) {
        // Display the faculty menu and get the choice
        choice = display_faculty_menu();

        // Based on the choice, call the respective methods
        switch (choice) {
            case 1:
                add_new_course();
                break;
            case 2:
                remove_offered_course();
                break;
            case 3:
                view_enrollments_in_courses();
                break;
            case 4:
                faculty_password_change();
                break;
            case 5:
                printf("Exiting...\n");
                close(client_socket);
                // close(server_socket);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    // decide if we have to close ot nnot
    // close(client_socket);
    // close(server_socket);
}