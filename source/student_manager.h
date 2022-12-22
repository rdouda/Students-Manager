#pragma once
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include "types.h"

void main_loop(Student[], int*);
void add_student(Student[], int*);
void remove_student(Student[], int*);
void update_student(Student[], const int);
void display_students(Student[], const int);
void sort_students(Student[], const int);

void display_student(Student);
void display_student_by_id(Student[], const int);
void display_students_by_level(Student[], const int);
void display_students_by_average(Student[], const int);
void display_general_average_by_level(Student[], const int);
void swap(Student*, Student*);
void save_data(Student[], const int);
void load_data(Student[], int*);

int    compare(const float, const float, const int, const int);
int    find_student_by_id(Student[], const int, const int);
char*  input();
int    strtoint(const char*);
char*  inttostr(const int);
float  strtoflt(const char*);
float  calculate_general_average_by_level(Student[], const int, const int);

#endif // !STUDENT_MANAGER_H
