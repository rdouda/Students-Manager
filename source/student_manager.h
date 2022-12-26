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
float command_similarity(const char*, const char*);
char* input();
void process_input();
#endif // !STUDENT_MANAGER_H
