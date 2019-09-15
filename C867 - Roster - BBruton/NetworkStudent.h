/*
   Scripting and Programming - Applications C867
   Language: C++
   Student ID# 000695605
   Benjamin Bruton
*/

#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "Student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent();

	NetworkStudent(string, string, string, string, int, int*, Degree);

	Degree getDegree() override;

	void print() override;


private:
	Degree degree;
};


#endif //NETWORKSTUDENT_H