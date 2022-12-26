#include "student_manager.h"

Functions functions[32] = {
		{"quit"    ,&quit},
		{"help"    ,&help},
		{"add"     ,&add},
		{"delete"  ,&delete},
		{"find"    ,&find},
		{"update"  ,&update},
		{"list"    ,&list},
		{"sort"    ,&sort},
		{"average" ,&average},
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
		process_input();
		printf("\nPress any key to return.\n");
		int k = _getch();
	}
	save_data();
}

/*
	Commands
*/
void help(){
	printf("Available commands : \n");
	for (int i = 0; i < COMMANDS_COUNT; i++)
		printf("%02d. %s\n", i + 1, functions[i].name);
}

void add() {
	printf("ADD");
}

void delete(){
	printf("DELETE");
}

void find(){
	printf("FIND");
}

void update(){
	printf("UPDATE");
}

void list(){
	printf("LIST");
}

void sort(){
	printf("SORT");
}

void average(){
	printf("AVERAGE");
}

void quit() {
	WindowShouldClose = true;
}
/*
	End Commands
*/

void save_data(){
}

void load_data(){
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

void process_input(){
	printf(" > ");
	char* in = input();
	for (int i = 0; i < COMMANDS_COUNT; i++)
		if (command_similarity(in, functions[i].name) >= 0.75) {
			(*functions[i].function)();
			return;
		}
	printf("Unknown command type 'help' for commands.\n");
}
