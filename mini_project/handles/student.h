#ifndef STUDENT_H
#define STUDENT_H
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100
#define STUDENT_FILE "files/student"
#define COURSE_FILE "files/course"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char id[MAX_NAME_LENGTH];
    int status;  // 0 for deactivated, 1 for active
    int count;
} Student;


int display_student_menu();
void enroll_courses();
void unenroll_courses();
void view_enrolled_courses();
void change_password();
#endif
