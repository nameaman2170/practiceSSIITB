#include <stdio.h>
#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Define a structure for a course
typedef struct Course {
    char course_code[MAX_NAME_LENGTH];
    char course_name[MAX_NAME_LENGTH];
    int enrolled;  // 0 for not enrolled, 1 for enrolled
} Course;

int display_student_menu() {
    printf("Student Menu:\n");
    printf("1. Enroll to new Courses\n");
    printf("2. Unenroll from already enrolled Courses\n");
    printf("3. View enrolled Courses\n");
    printf("4. Password Change\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}


bool isValidCourse(char course_id[]){
    char line[MAX_LINE_LENGTH];
    FILE *course_file = fopen(COURSE_FILE, "r");
    if (course_file == NULL) {
        fclose(course_file);
        perror("Error opening course file");
        exit(1);
    }
    // Read each line in the file and update the status for the given student
    while (fgets(line, sizeof(line), course_file) != NULL) {
        char *id = strstr(line, course_id);
        if (id != NULL) {
            return true;
        }
    }
    return false;
}

void displayCoursesFile(){

}

void updateCountOfStudent(char student_id[]){
    FILE *file = fopen(STUDENT_FILE, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fseek(file, 0, SEEK_SET);
    char line[MAX_LINE_LENGTH];
    int found = 0;  // Flag to indicate if the student was found

    // Read each line in the file and update the status for the given student
    while (fgets(line, sizeof(line), file) != NULL) {
        char *id = strstr(line, student_id);
        printf("id is: %s\n", id);
        if (id != NULL) {
            char *enrolled_courses_ptr = strstr(line, "enrolled_courses:");
            if (enrolled_courses_ptr != NULL) {
                found = 1;
                enrolled_courses_ptr = enrolled_courses_ptr + strlen("enrolled_courses:");
                char *token = strtok(enrolled_courses_ptr, ",");
                int new_enrolled_courses = atoi(token);
                memset(enrolled_courses_ptr, ' ', 2);
                snprintf(enrolled_courses_ptr, sizeof(new_enrolled_courses), "%d", new_enrolled_courses);
                break;
            }
        }
    }

    // If student is found, update the file
    if (found) {
        fseek(file, -strlen(line), SEEK_CUR);
        // memset(file, ' ', strlen(line));
        fprintf(file, "%s", line);
        printf("Student status updated in student.txt\n");
    } else {
        printf("Student with ID %s not found.\n", student_id);
    }

    fclose(file);
}

// Function to enroll in new courses
void enroll_courses() {
    char student_id[MAX_NAME_LENGTH];
    char course_id[MAX_NAME_LENGTH];
    printf("Enter your student ID: ");
    scanf("%s", student_id);
    //verify if valid user ID
    displayCoursesFile();
    //display the couses and take the course_id from user to enroll
    printf("select one choice from above courses: \n Enter the Course_ID: \n");
    scanf("%s", course_id);
    if(isValidCourse(course_id)){
        printf("Valid course ID: ...\n");
        updateCountOfStudent(student_id);
        return;
    }else{
        printf("Invalid course: \n");
        return;
    }
    fclose(student_file);
    fclose(course_file);
}

// Function to unenroll from already enrolled courses
void unenroll_courses() {
    /*char student_id[MAX_NAME_LENGTH];
    printf("Enter your student ID: ");
    scanf("%s", student_id);

    FILE *student_file = fopen(STUDENT_FILE, "r+");
    if (student_file == NULL) {
        perror("Error opening student file");
        return;
    }

    FILE *course_file = fopen(COURSE_FILE, "r+");
    if (course_file == NULL) {
        fclose(student_file);
        perror("Error opening course file");
        return;
    }

    int found_student = 0;
    Student student;

    // Search for the student by their ID
    while (fread(&student, sizeof(Student), 1, student_file)) {
        if (strcmp(student.id, student_id) == 0) {
            found_student = 1;
            break;
        }
    }

    if (!found_student) {
        printf("Student with ID %s not found.\n", student_id);
        fclose(student_file);
        fclose(course_file);
        return;
    }

    char course_code[MAX_NAME_LENGTH];
    printf("Enter the course code you want to unenroll from: ");
    scanf("%s", course_code);

    int found_course = 0;
    Course course;

    // Search for the course by its code
    while (fread(&course, sizeof(Course), 1, course_file)) {
        if (strcmp(course.course_code, course_code) == 0) {
            found_course = 1;

            // Check if the course is already unenrolled
            if (!course.enrolled) {
                printf("You are not enrolled in this course.\n");
                fclose(student_file);
                fclose(course_file);
                return;
            }

            // Unenroll the student from the course
            fseek(course_file, -sizeof(Course), SEEK_CUR);
            course.enrolled = 0;
            fwrite(&course, sizeof(Course), 1, course_file);

            printf("Successfully unenrolled from course %s: %s\n", course.course_code, course.course_name);
            break;
        }
    }

    if (!found_course) {
        printf("Course with code %s not found.\n", course_code);
    }

    fclose(student_file);
    fclose(course_file);*/
}

void view_enrolled_courses() {
    /*char student_id[MAX_NAME_LENGTH];
    printf("Enter your student ID: ");
    scanf("%s", student_id);

    FILE *student_file = fopen(STUDENT_FILE, "r");
    if (student_file == NULL) {
        perror("Error opening student file");
        return;
    }

    FILE *course_file = fopen(COURSE_FILE, "r");
    if (course_file == NULL) {
        fclose(student_file);
        perror("Error opening course file");
        return;
    }

    int found_student = 0;
    Student student;

    // Search for the student by their ID
    while (fread(&student, sizeof(Student), 1, student_file)) {
        if (strcmp(student.id, student_id) == 0) {
            found_student = 1;
            break;
        }
    }

    if (!found_student) {
        printf("Student with ID %s not found.\n", student_id);
        fclose(student_file);
        fclose(course_file);
        return;
    }

    printf("Enrolled courses for student %s:\n", student_id);

    Course course;

    // Print enrolled courses
    while (fread(&course, sizeof(Course), 1, course_file)) {
        if (course.enrolled && course.course_code[0] != '\0') {
            printf("Course Code: %s, Course Name: %s\n", course.course_code, course.course_name);
        }
    }

    fclose(student_file);
    fclose(course_file);*/
}

void change_password() {
/*    char student_id[MAX_NAME_LENGTH];
    printf("Enter your student ID: ");
    scanf("%s", student_id);

    FILE *student_file = fopen(STUDENT_FILE, "r+");
    if (student_file == NULL) {
        perror("Error opening student file");
        return;
    }

    int found_student = 0;
    Student student;

    // Search for the student by their ID
    while (fread(&student, sizeof(Student), 1, student_file)) {
        if (strcmp(student.student_id, student_id) == 0) {
            found_student = 1;
            break;
        }
    }

    if (!found_student) {
        printf("Student with ID %s not found.\n", student_id);
        fclose(student_file);
        return;
    }

    printf("Enter your new password: ");
    scanf("%s", student.password);

    // Update the password for the student
    fseek(student_file, -sizeof(Student), SEEK_CUR);
    fwrite(&student, sizeof(Student), 1, student_file);

    printf("Password changed successfully for student %s.\n", student_id);

    fclose(student_file);*/

}