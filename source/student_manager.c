#include "student_manager.h"

void main_loop(Student students[], int* students_count){
	while (1) {
		system("cls");
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
		int choice = strtoint(input());
		system("cls");
		switch (choice) {
			case 0: save_data(students, *students_count); exit(0);
			case 1: add_student(students, students_count); break;
			case 2: remove_student(students, students_count); break;
			case 3: update_student(students, *students_count); break;
			case 4: display_students(students, *students_count); break;
			case 5: display_student_by_id(students, *students_count); break;
			case 6: display_students_by_level(students, *students_count); break;
			case 7: display_students_by_average(students, *students_count); break;
			case 8: display_general_average_by_level(students, *students_count); break;
			case 9: sort_students(students, *students_count); break;
		default:
			break;
		}
		printf("\nPress any key to return.");
		int k = _getch();
	}
}

void add_student(Student students[], int *size){
	Student student;
	char temp;
	while(1){
		printf("Enter 'cancel' to return.\n");
		printf("Enter student id      : ");
		char* in = input();
		if (strcmp(in, "cancel") == 0)
			return;
		student.id = strtoint(in);
		if (find_student_by_id(students, *size, student.id) != -1)
			printf("Student with id = %d already exist.\n", student.id);
		else
			break;
	}
	printf("Enter student level   : ");
	scanf_s("%d", &student.level);
	printf("Enter student average : ");
	scanf_s("%f", &student.average);
	printf("Enter student name    : ");
	scanf_s("%c", &temp, (unsigned int)sizeof(temp));
	scanf_s("%[^\n]", student.name, (unsigned int)sizeof(student.name));

	students[*size].id = student.id;
	students[*size].average = student.average;
	students[*size].level = student.level;
	strcpy_s(students[*size].name, sizeof(students[*size].name), student.name);

	*size = *size + 1;
	printf("Student added successfully.\n");
}

void remove_student(Student students[], int* size){
	if (*size == 0) {
		printf("List is empty.");
		return;
	}
	printf("Enter 'cancel' to return.\n");
	printf("Enter 'remove all' to removeall students.\n");
	printf("Enter student id to delete : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	if (strcmp(in, "removeall") == 0){
		*size = 0;
		save_data(students, *size);
		return;
	}
	int id = strtoint(in);
	int index_to_remove = find_student_by_id(students, *size, id);
	if (index_to_remove == -1) {
		printf("Student %d was not found.\n", id);
		return;
	}
	for (int i = index_to_remove; i < *size - 1; i++) {
		students[i].id = students[i + 1].id;
		students[i].level = students[i + 1].level;
		students[i].average = students[i + 1].average;
		strcpy_s(students[i].name, sizeof(students[i].name), students[i + 1].name);
	}
	*size = *size - 1;
	printf("Student %d removed successfully.\n", id);
}

void update_student(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	Student student;
	printf("Enter 'cancel' to return.\n");
	printf("Enter student id to update : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	int id = strtoint(in);
	int index = find_student_by_id(students, size, id);
	if (index == -1){
		printf("Student %d was not found.\n", id);
		return;
	}
	printf("Enter student id      : ");
	scanf_s("%d", &student.id);
	printf("Enter student level   : ");
	scanf_s("%d", &student.level);
	printf("Enter student average : ");
	scanf_s("%f", &student.average);
	printf("Enter student name    : ");
	scanf_s("%s", student.name, (unsigned int)sizeof(student.name));
	students[index].id = student.id;
	students[index].average = student.average;
	students[index].level = student.level;
	memset(students[index].name, 0, sizeof(students[index].name));
	strcpy_s(students[index].name, sizeof(students[index].name), student.name);
	printf("Student updated successfully.\n");
}

void display_students(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	for (int i = 0; i < size; i++) {
		display_student(students[i]);
	}
}

void sort_students(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (compare(students[j].average, students[min_index].average, students[j].level, students[min_index].level)) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(&students[i], &students[min_index]);
		}
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (students[j].level > students[j + 1].level)
				swap(&students[j], &students[j + 1]);
	printf("Operation successfull.\n");
}

void display_student(Student student) {
	printf("STUDENT ID[ %d ]\n", student.id);
	printf(" STUDENT ID       : %d\n", student.id);
	printf(" STUDENT LEVEL    : %d\n", student.level);
	printf(" STUDENT AVERAGE  : %f\n", student.average);
	printf(" STUDENT NAME     : %s\n", student.name);
}

void display_student_by_id(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	printf("Enter 'cancel' to return.\n");
	printf("Enter student id : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	int id = strtoint(in);
	int index = find_student_by_id(students, size, id);
	if (index == -1) {
		printf("Student %d was not found.", id);
		return;
	}
	display_student(students[index]);
}

void display_students_by_level(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	printf("Enter 'cancel' to return.\n");
	printf("Enter students level : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	int level = strtoint(in);
	int found = 0;
	for (int i = 0; i < size; i++) {
		if (students[i].level == level)
			found++;
	}
	if (found > 0) {
		for (int i = 0; i < size; i++) {
			if (students[i].level == level)
				display_student(students[i]);
		}
		return;
	}
	printf("Students with level %d was not found.", level);
}

void display_students_by_average(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	printf("Enter 'cancel' to return.\n");
	printf("Enter students average : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	float average = strtoflt(in);
	int found = 0;
	printf("Students average in range[%f %f]\n", floor(average), ceil(average));
	for (int i = 0; i < size; i++) {
		if(students[i].average <= ceil(average) && students[i].average >= floor(average)){
			display_student(students[i]);
		}
	}
}

void display_general_average_by_level(Student students[], const int size){
	if (size == 0) {
		printf("List is empty.");
		return;
	}
	printf("Enter 'cancel' to return.\n");
	printf("Enter students level : ");
	char* in = input();
	if (strcmp(in, "cancel") == 0)
		return;
	int level = strtoint(in);
	printf("\nStudents average : %f", calculate_general_average_by_level(students, size, level));
}

void swap(Student* sa, Student* sb) {
	Student stt;
	stt.id = sa->id;
	stt.level = sa->level;
	stt.average = sa->average;
	strcpy_s(stt.name, sizeof(stt.name), sa->name);

	sa->id = sb->id;
	sa->level = sb->level;
	sa->average = sb->average;
	memset(sa->name, 0, sizeof(sa->name));
	strcpy_s(sa->name, sizeof(sa->name), sb->name);

	sb->id = stt.id;
	sb->level = stt.level;
	sb->average = stt.average;
	memset(sb->name, 0, sizeof(sb->name));
	strcpy_s(sb->name, sizeof(sb->name), stt.name);
}

void save_data(Student students[], const int size){
	FILE* file;
	errno_t err = fopen_s(&file, "data.bin", "w");
	if (err != 0)
		return;
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			fwrite(&students[i], sizeof(Student), 1, file);
		}
	}
	fclose(file);
}

void load_data(Student students[], int* size){
	FILE* file;
	*size = 0;
	errno_t err = fopen_s(&file, "data.bin", "r");
	if (err != 0)
		return;
	for (int i = 0; i < MAX_STUDENTS; i++){
		if (fread(&students[i], sizeof(Student), 1, file) > 0)
			*size = *size + 1;
	}
	fclose(file);
	if(*size == 0)
		save_data(students, *size);
}

char* input(){
	static char in[20];
	scanf_s("%s", in, (unsigned int)sizeof(in));
	return in;
}

int strtoint(const char* str){
	char* nullp;
	int i = strtol(str, &nullp, 10);
	if (*nullp == '\0')
		return i;
	return 0;
}

char* inttostr(const int i){
	static char str[32];
	memset(str, 0, sizeof(str));
	sprintf_s(str, 32,"%d", i);
	return str;
}

float strtoflt(const char* str){
	char* nullp;
	float f = strtof(str, &nullp);
	if (*nullp == '\0')
		return f;
	return 0.0f;
}

int compare(const float a1, const float a2, const int l1, const int l2){
	return (a1 < a2 || (a1 == a2 && l1 < l2));
}

int find_student_by_id(Student students[], const int size, const int id){
	for (int i = 0; i < size; i++){
		if (students[i].id == id)
			return i;
	}
	return -1;
}

float calculate_general_average_by_level(Student students[], const int size, const int level){
	float sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (students[i].level == level) {
			sum += students[i].average;
			count++;
		}
	}
	if (sum == 0 && count == 0)
		return 0.0f;
	return sum / count;
}
