#include <stdio.h>
#include "student.h"

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

void enroll_courses() {
    printf("Enrolling to new Courses...\n");
    // Implement the logic for enrolling to new courses here
}

void unenroll_courses() {
    printf("Unenrolling from already enrolled Courses...\n");
    // Implement the logic for unenrolling from courses here
}

void view_enrolled_courses() {
    printf("Viewing enrolled Courses...\n");
    // Implement the logic for viewing enrolled courses here
}

void password_change() {
    printf("Changing Password...\n");
    // Implement the logic for changing password here
}