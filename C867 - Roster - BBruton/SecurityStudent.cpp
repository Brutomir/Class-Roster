/*
   Scripting and Programming - Applications C867
   Language: C++
   Student ID# 000695605
   Benjamin Bruton
*/

#include "SecurityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent() {}

SecurityStudent::SecurityStudent(string studID, string fiName, string laName, string emAddr, int a, int *nmDays, Degree deg) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degree = deg;
}

Degree SecurityStudent::getDegree() {
	return degree;
}

void SecurityStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "Days in Course: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Security" << '\n';
}