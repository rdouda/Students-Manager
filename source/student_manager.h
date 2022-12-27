#pragma once
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "inc.h"

static Students* students;
static bool WindowShouldClose = false;

void init();
void smgr();

/*
	Commands
*/
void help();
void add();
void delete();
void find();
void update();
void list();
void sort();
void average();
void quit();
/*
	Commands
*/

void save_data();
void load_data();

/*
	Utils
*/
char* input();
int strtoint(const char*);
char* inttostr(const int);
float strtoflt(const char*);
void process_input();
void display_student(Student);
int find_student_by_id(int);
void swap(Student*, Student*);
#endif // !STUDENT_MANAGER_H
