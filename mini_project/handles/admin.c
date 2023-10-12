#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char id[MAX_NAME_LENGTH];
    int status;  // 0 for deactivated, 1 for active
} Student;

// Structure to hold faculty information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char id[MAX_NAME_LENGTH];
} Faculty;


int display_admin_menu() {
    printf("Admin Menu:\n");
    printf("1. Add Student\n");
    printf("2. Add Faculty\n");
    printf("3. Activate/Deactivate Student\n");
    printf("4. Update Student/Faculty details\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void add_student() {
    Student new_student;

    // Prompt for student details
    printf("Enter student name: ");
    scanf("%s", new_student.name);

    printf("Enter student age: ");
    scanf("%d", &new_student.age);

    printf("Enter student ID: ");
    scanf("%s", new_student.id);
    new_student.status = 1;
    // Open the file in append mode
    FILE *file = fopen("files/student", "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Append student details to the file
    fprintf(file, "Name: %s, Age: %d, ID: %s, Status: %d\n", 
        new_student.name, new_student.age, new_student.id, new_student.status);
    // Close the file
    fclose(file);

    printf("Student details added to student.txt\n");
}

void add_faculty() {
    Faculty new_faculty;

    // Prompt for faculty details
    printf("Enter faculty name: ");
    scanf("%s", new_faculty.name);

    printf("Enter faculty age: ");
    scanf("%d", &new_faculty.age);

    printf("Enter faculty ID: ");
    scanf("%s", new_faculty.id);

    // Open the file in append mode
    FILE *file = fopen("files/faculty", "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Append faculty details to the file
     fprintf(file, "Name: %s, Age: %d, ID: %s\n",
        new_faculty.name, new_faculty.age, new_faculty.id);

    // Close the file
    fclose(file);

    printf("Faculty details added to faculty.txt\n");
}

void activate_deactivate_student() {
    
    char student_id[MAX_NAME_LENGTH];
    int new_status;

    // Prompt for student ID and new status
    printf("Enter new status (0 for deactivated, 1 for active): ");
    scanf("%d", &new_status);

    printf("Enter student ID: ");
    scanf("%s", student_id);


    FILE *file = fopen("files/student", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    lseek(fileno(file), 0, SEEK_SET);
    char line[MAX_LINE_LENGTH];
    int found = 0;  // Flag to indicate if the student was found

    // Read each line in the file and update the status for the given student
    while (fgets(line, sizeof(line), file) != NULL) {
        char *id = strstr(line, student_id);
        printf("id is: %s\n", id);
        if (id != NULL) {
            char *status_ptr = strstr(line, "Status:");
            if (status_ptr != NULL) {
                found = 1;
                status_ptr = status_ptr + 8;
                memset(status_ptr, ' ', 1);
                snprintf(status_ptr, 2, "%d", new_status);
                break;
            }
        }
    }

    // If student is found, update the file
    if (found) {
        fseek(file, -strlen(line)-1, SEEK_CUR);
        // memset(file, ' ', strlen(line));
        fprintf(file, "%s", line);
        printf("Student status updated in student.txt\n");
    } else {
        printf("Student with ID %s not found.\n", student_id);
    }

    fclose(file);
}

void replaceSubstringAt(char *string, char *index, char replace[]) {
    int replaceLen = strlen(replace);
    int stringLen = strlen(string);
    int offset = index - string;

    // Shift the rest of the string to accommodate the new substring
    memmove(index + replaceLen, index + strlen(replace), stringLen - offset - strlen(replace) + 1);

    // Replace the substring
    strncpy(index, replace, replaceLen);
}

void update_student_faculty_details() {
    char type;
    printf("For student, enter [s], and for faculty, enter [f]: \n");
    scanf(" %c", &type);  // Added a space before %c to consume the newline character

    if (type == 's') {
        char student_id[MAX_NAME_LENGTH];
        char new_id[MAX_NAME_LENGTH];

        printf("Enter the ID of student you want to update: ");
        scanf("%s", student_id);

        printf("Enter the new ID: ");
        scanf("%s", new_id);

        FILE *file = fopen("files/student", "r+");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        char line[MAX_LINE_LENGTH];
        int found = 0;  // Flag to indicate if the student was found

        while (fgets(line, sizeof(line), file) != NULL) {
            char *id_position = strstr(line, student_id);
            if (id_position != NULL) {
                found = 1;

                // Move the file pointer to the ID position and update it
                fseek(file, id_position - line, SEEK_CUR);
                fprintf(file, "ID: %s", new_id);

                break;
            }
        }

        if (found) {
            printf("Student ID updated in student.txt\n");
        } else {
            printf("Student with ID %s not found.\n", student_id);
        }

        fclose(file);
}else {
        printf("Faculty changes\n");
    }
}
