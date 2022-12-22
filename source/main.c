#include "student_manager.h"

Student students[MAX_STUDENTS];
int students_count = 0;

int main(int agc, const char *agv[]) {
	load_data(students, &students_count);
	main_loop(students, &students_count);
	return 0;
}
