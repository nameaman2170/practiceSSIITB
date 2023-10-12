#include <stdio.h>
#include "faculty.h"

int display_faculty_menu() {
    printf("Faculty Menu:\n");
    printf("1. Add new Course\n");
    printf("2. Remove offered Course\n");
    printf("3. View enrollments in Courses\n");
    printf("4. Password Change\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void add_new_course() {
    printf("Adding new Course...\n");
    // Implement the logic for adding a new course here
}

void remove_offered_course() {
    printf("Removing offered Course...\n");
    // Implement the logic for removing an offered course here
}

void view_enrollments_in_courses() {
    printf("Viewing enrollments in Courses...\n");
    // Implement the logic for viewing enrollments in courses here
}

void faculty_password_change() {
    printf("Changing Password...\n");
    // Implement the logic for changing password here
}