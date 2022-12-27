#include "student_manager.h"

Functions functions[32] = {
		{"quit"    ,"Save data and quit.", &quit},
		{"help"    ,"Show commmands.",&help},
		{"add"     ,"Add a student.",&add},
		{"remove"  ,"Remove a student.",&delete},
		{"find"    ,"Find a student.",&find},
		{"update"  ,"Update student information.",&update},
		{"list"    ,"Display the list of students.",&list},
		{"sort"    ,"Sort students by level and average.",&sort},
		{"average" ,"Calculate general average by level.",&average},
};

void init(){
	students = malloc(sizeof(Students));
	if (students == NULL)
		exit(EXIT_FAILURE);
	load_data();
}

void smgr(){
	while (!WindowShouldClose) {
		system("cls");
		printf("\n     Student Manager\n\n");
		printf("Type 'help' for commands\n");
		process_input();
		if(!WindowShouldClose){
			printf("\nPress any key to return.\n");
			int k = _getch();
		}
	}
}

/*
	Commands
*/
void help(){
	printf("Available commands : \n");
	for (int i = 0; i < COMMANDS_COUNT; i++)
		printf("%02d. %s - %s\n", i + 1, functions[i].name, functions[i].description);
}

void add() {
	printf("ADD STUDENT\n");
	if (students->size + 1 == MAX_STUDENTS) {
		printf("Memory is full.");
		return;
	}
	int size = students->size;
	printf("Enter student id : ");
	int id = strtoint(input());
	while(find_student_by_id(id) != -1)
		id = strtoint(input());
	students->students[size].id = id;

	printf("Enter student name : ");
	char* name = input();
	while (strlen(name) < 3)
		name = input();
	strcpy_s(students->students[size].name, sizeof(students->students[size].name), name);

	printf("Enter student level : ");
	int level = strtoint(input());
	while (level < 0 || level > 5)
		level = strtoint(input());
	students->students[size].level = level;

	printf("Enter student average : ");
	float average = strtoflt(input());
	while(average < 0 || average > 20)
		average = strtoflt(input());
	students->students[size].average = average;

	students->size++;
	printf("Student added.");
}

void delete(){
	printf("REMOVE STUDENT\n");
	printf("Enter student id : ");
	int id = strtoint(input());
	int index_remove = find_student_by_id(id);
	if (index_remove == -1) {
		printf("Student with id %d not found.", id);
		return;
	}
	printf("Student removed successfully.\n");
	swap(&students->students[index_remove], &students->students[students->size - 1]);
	students->size--;
}

void find(){
	printf("FIND");
}

void update(){
	printf("UPDATE");
}

void list(){
	if (students->size == 0)
		printf("List is empty.");
	for (int i = 0; i < students->size; i++)
		display_student(students->students[i]);
}

void sort(){
	printf("SORT");
}

void average(){
	printf("AVERAGE");
}

void quit() {
	WindowShouldClose = true;
	save_data();
	free(students);
}
/*
	End Commands
*/

void save_data(){
}

void load_data(){
	students->size = 0;
}

/*
	Utils
*/
float command_similarity(const char* c1, const char* c2){
	int common_chars = 0;
	int total_chars = 0;
	while (*c1 || *c2) {
		if (*c1 == *c2)
			common_chars++;
		total_chars++;
		c1++;
		c2++;
	}
	return (float) common_chars / total_chars;
}

char* input(){
	static char in[32];
	memset(in, 0, sizeof(in));
	scanf_s("%s", in, (unsigned int)sizeof(in));
	return in;
}

int strtoint(const char* str) {
	char* nullp;
	int i = strtol(str, &nullp, 10);
	if (*nullp == '\0')
		return i;
	return 0;
}

char* inttostr(const int i) {
	static char str[32];
	memset(str, 0, sizeof(str));
	sprintf_s(str, 32, "%d", i);
	return str;
}

float strtoflt(const char* str) {
	char* nullp;
	float f = strtof(str, &nullp);
	if (*nullp == '\0')
		return f;
	return 0.0f;
}

void process_input(){
	printf(" > ");
	char* in = input();
	for (int i = 0; i < COMMANDS_COUNT; i++){
		if (strcmp(in, functions[i].name) == 0) {
			system("cls");
			(*functions[i].function)();
			return;
		}
	}
	printf("Unknown command type 'help' for commands.\n");
}

void display_student(Student student) {
	printf("\n - STUDENT [ %d ] - \n", student.id);
	printf(" STUDENT ID      : %d\n", student.id);
	printf(" STUDENT NAME    : %s\n", student.name);
	printf(" STUDENT LEVEL   : %d\n", student.level);
	printf(" STUDENT AVERAGE : %f\n", student.average);
}

int find_student_by_id(int id){
	for (int i = 0; i < students->size; i++) {
		if (students->students[i].id == id)
			return i;
	}
	return -1;
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