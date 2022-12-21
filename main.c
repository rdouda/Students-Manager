#include "student_manager.h"

Student students[MAX_STUDENTS];
int students_count = 0;

void t_add_students(Student students[], int* size) {
	Student s1 = { 4, 2, 12.4, "rad" };
	Student s2 = { 6, 2, 11.1, "7san" };
	Student s3 = { 8, 1, 14.8, "geh" };
	Student s4 = { 3, 6, 13.9, "puta" };

	students[0].id = s1.id;
	students[0].level = s1.level;
	students[0].average = s1.average;
	strcpy_s(students[0].name, sizeof(students[0].name), s1.name);

	students[1].id = s2.id;
	students[1].level = s2.level;
	students[1].average = s2.average;
	strcpy_s(students[1].name, sizeof(students[1].name), s2.name);

	students[2].id = s3.id;
	students[2].level = s3.level;
	students[2].average = s3.average;
	strcpy_s(students[2].name, sizeof(students[2].name), s3.name);

	students[3].id = s4.id;
	students[3].level = s4.level;
	students[3].average = s4.average;
	strcpy_s(students[3].name, sizeof(students[3].name), s4.name);

	*size = *size + 4;
}

void main_menu() {
	t_add_students(students, &students_count);
	while (1) {
		system("cls");
		int choice;
		printf(" Please specify the operation you want to be performed.\n");
		printf(" 0. Exit the application.\n");
		printf(" 1. Add a student.\n");
		printf(" 2. Remove a student.\n");
		printf(" 3. Update a student.\n");
		printf(" 4. Display the list of students.\n");
		printf(" 5. Find a student by id.\n");
		printf(" 6. Find students by level.\n");
		printf(" 7. Find students by average.\n");
		printf(" 8. Calculate the general average by level.\n");
		printf(" 9. Sort students\n");
		printf(" > ");
		do {
			scanf_s("%d", &choice);
		} while (choice > 9 || choice < 0);
		system("cls");
		switch (choice) {
			case 0: exit(0); break;
			case 1: add_student(students, &students_count); break;
			case 2: remove_student(students, &students_count); break;
			case 3: update_student(students, students_count); break;
			case 4: display_students(students, students_count); break;
			case 5: display_student_by_id(students, students_count); break;
			case 6: display_students_by_level(students, students_count); break;
			case 7: display_students_by_average(students, students_count); break;
			case 8: display_general_average_by_level(students, students_count); break;
			case 9: sort_students(students, students_count); break;
			default:
				break;
		}
		printf("\nPress any key to return.");
		int k = _getch();
	}
}

int main(int agc, const char *agv[]) {
	main_menu();
	return 0;
}
