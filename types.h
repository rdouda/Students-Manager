#pragma once
#ifndef TYPES_H
#define TYPES_H

#define MAX_STUDENTS 1024

typedef struct {
	int id;
	int level;
	float average;
	char name[30];
}Student;

#endif // !TYPES_H
