/*
   Scripting and Programming - Applications C867
   Language: C++
   Student ID# 000695605
   Benjamin Bruton
*/

#include "NetworkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent() {}

NetworkStudent::NetworkStudent(string studID, string fiName, string laName, string emAddr, int a, int *nmDays, Degree deg) : Student(studID, fiName, laName, emAddr, a, nmDays) {
	degree = deg;
}

Degree NetworkStudent::getDegree() {
	return degree;
}

void NetworkStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "Days in Course: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Networking" << '\n';
}