#include "student_manager.h"

void init(){
	students = malloc(sizeof(Students));
	if (students == NULL)
		exit(EXIT_FAILURE);
	load_data();
}

void smgr(){
	char command[32];
	while (!WindowShouldClose) {
		system("cls");
		show_menu();
		scanf_s("%s", command, (unsigned int)sizeof(command));
		switch (process_command(command))
		{
			case 0: {
				continue; break;
			}
			case 1: {
				show_commands();
				break;
			}
			case 2: {
				WindowShouldClose = true;
			}
			case 3: {
				add_student(); 
				break;
			}
			case 4: {
				remove_student();
				break;
			}
			case 5: {
				update_student();
				break;
			}
			case 6: {
				list_students();
				break;
			}
			case 7: {
				find_student();
				break;
			}
			case 8: {
				get_average();
				break;
			}
			case 9: {
				sort_students();
				break;
			}
			default:
				break;
		}
		if (WindowShouldClose)
			return;
		printf("\nPress any key to return.\n");
		int k = _getch();
	}
}

void quit(){
	free(students);
	exit(EXIT_SUCCESS);
}

void show_menu(){
	printf(" Please specify the operation you want to be performed.\n");
	printf(" Type 'help' for commands.\n");
	printf(" > ");
}

void show_commands(){
	printf("\nAvailable commands:\n");
	printf("quit\n");
	printf("help\n");
	printf("add\n");
	printf("remove\n");
	printf("update\n");
	printf("list\n");
	printf("find\n");
	printf("average\n");
	printf("sort\n");
}

void add_student() {
}

void remove_student(){
}

void find_student(){
}

void update_student(){
}

void list_students(){
}

void sort_students(){
}

void get_average(){
}

void save_data(){
}

void load_data(){
	students->top = 0;
}

int process_command(char* command){
	if (command_similarity(command, "help") >= 0.75)
		return 1;
	if (command_similarity(command, "quit") >= 0.75)
		return 2;
	if (command_similarity(command, "add") >= 0.75)
		return 3;
	if (command_similarity(command, "remove") >= 0.75)
		return 4;
	if (command_similarity(command, "update") >= 0.75)
		return 5;
	if (command_similarity(command, "list") >= 0.75)
		return 6;
	if (command_similarity(command, "find") >= 0.75)
		return 7;
	if (command_similarity(command, "average") >= 0.75)
		return 8;
	if (command_similarity(command, "sort") >= 0.75)
		return 9;
	return 0;
}

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
