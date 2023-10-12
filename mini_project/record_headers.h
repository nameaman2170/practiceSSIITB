/* Structure to hold information about a course */
struct course {
    int course_id;
    char course_name[50];
    int credits;
    int duration; // in semesters or years
};

/* Structure to hold information about a student */
struct student {
    int student_id;
    char student_name[50];
    int age;
    char student_gender;
    char student_address[100];
    int course_ids[10]; // Array of course IDs the student is enrolled in
    int num_courses;    // Number of courses the student is enrolled in
};

/* Structure to hold information about an administrator */
struct administrator {
    int admin_id;
    char admin_name[50];
    char admin_login_id[20];
    char admin_password[20];
};

/* Structure to hold information about a faculty member */
struct faculty {
    int faculty_id;
    char faculty_name[50];
    char faculty_position[50];
    int course_ids[10]; // Array of course IDs taught by the faculty
    int num_courses;    // Number of courses taught by the faculty
};
