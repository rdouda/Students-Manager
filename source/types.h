#pragma once
#ifndef TYPES_H
#define TYPES_H

#define MAX_STUDENTS 1024
#define COMMANDS_COUNT 9

typedef struct {
	int id;
	int level;
	float average;
	char name[30];
}Student;

typedef struct {
	Student students[MAX_STUDENTS];
	int size;
}Students;

typedef struct {
	char name[32];
	char description[64];
	void (*function)();
}Functions;

#endif // !TYPES_H
