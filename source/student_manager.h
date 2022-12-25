#pragma once
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "inc.h"

static Students* students;
static bool WindowShouldClose = false;

void init();
void smgr();
void quit();

void show_menu();
void show_commands();
void add_student();
void remove_student();
void update_student();
void display_students();
void sort_students();

void display_student();
void display_student_by_id();
void display_students_by_level();
void display_students_by_average();
void display_general_average_by_level();

void save_data();
void load_data();

int process_command(char*);
float command_similarity(const char*, const char*);

#endif // !STUDENT_MANAGER_H
