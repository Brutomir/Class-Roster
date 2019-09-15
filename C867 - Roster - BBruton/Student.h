/*
   Scripting and Programming - Applications C867
   Language: C++
   Student ID# 000695605
   Benjamin Bruton
*/

#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "Degree.h"
using namespace std;

class Student
{

public:

	// CONSTRUCTOR
	Student();

	//Student(string studID, string fiName, string laName, string emAddr, int a, int* nmDays);
	Student(string, string, string, string, int, int*);

	// ACCESSORS FOR EACH INSTANCE VARIABLE
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentID();
	int getAge();
	int *getNumDays();


	// MUTATOR FOR EACH INSTANCE VARIABLE
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setStudentID(string studentID);
	void setNumDays(int day0, int day1, int day2);
	void setDegree(string degree);

	virtual void print();
	virtual Degree getDegree();

	// DECONSTRUCTOR
	~Student();

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
};


#endif //STUDENT_H_
