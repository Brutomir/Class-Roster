/*
   Scripting and Programming - Applications C867
   Language: C++
   Student ID# 000695605
   Benjamin Bruton
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "SecurityStudent.h"
#include "Student.h"
#include "Degree.h"
#include "Roster.h"


using namespace std;


Roster::Roster() {}

//PRINTING ENTIRE STUDENT ROSTER
void Roster::printAll() {
	cout << "Roster:" << '\n';
	cout << endl;
	for (int i = 0; i < 5; i++) {
		(*classRosterArray[i]).print();
	}
	cout << '\n';
}

//THIS IS FOR UPDATING classRosterArray
void Roster::add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree degree) {
	int nmDaysIn[] = { day0, day1, day2 };
	if (degree == Degree::NETWORKING) {
		classRosterArray[addIndex++] = new NetworkStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SECURITY) {
		classRosterArray[addIndex++] = new SecurityStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SOFTWARE) {
		classRosterArray[addIndex++] = new SoftwareStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
}





//PRINTING AVERAGE DAYS TAKEN TO COMPLETE THREE COURSES
void Roster::printnumDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int avg = 0;
			avg = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "The average time in days it took the student with StudentID: " << studentID << " to finish three courses: " << avg << '\n';
		}
	}
	cout << '\n';
}


// PRINTING STUDENTS IN SPECIFIC DEGREE PROGRAM
void Roster::printByDegree(string degree) {
	Degree testDeg = Degree::SOFTWARE;
	if (degree == "SECURITY") {
		testDeg = Degree::SECURITY;
		cout << "Students in the Security Degree: " << endl;
	}
	if (degree == "NETWORKING") {
		testDeg = Degree::NETWORKING;
		cout << "Students in the Networking Degree: " << endl;
	}
	if (degree == "SOFTWARE") {
		testDeg = Degree::SOFTWARE;
		cout << "Students in the Software Degree: " << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if (testDeg == (*classRosterArray[i]).getDegree()) {
			(*classRosterArray[i]).print();
		}
	}
	cout << '\n';
}


// THIS IS FOR CHECKING AND DISPLAYING THE INVALID EMAILS
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << '\n';
	cout << endl;
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
		for (char &c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << '\n';
		}
	}
	cout << '\n';
}


// REMOVES STUDENT FROM ROSTER BY STUDENT ID
void Roster::remove(string studentID) {
	bool removed = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				removed = true;
			}
		}
	}
	if (!removed) {
		cout << "The student with the StudentID: " << studentID << " was not found." << '\n';
	}
}



int main()
{

	const string studentData[] =
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Benjamin,Bruton,bbruton@wgu.edu,33,10,11,12,SOFTWARE"
	};

	// CREATING Roster INSTANCE
	Roster classRoster;

	// CREATING Degree INSTANCE
	Degree myDegree;

	// ADD EACH STUDENT TO classRoster
	for (int i = 0; i < 5; i++) {
		stringstream ss(studentData[i]);

		vector<string> result;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}
		if (result[8] == "SECURITY") {
			myDegree = Degree::SECURITY;
		}
		if (result[8] == "SOFTWARE") {
			myDegree = Degree::SOFTWARE;
		}
		if (result[8] == "NETWORK") {
			myDegree = Degree::NETWORKING;
		}
		classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
			stoi(result[6]), stoi(result[7]), myDegree);
	}



	// PRINTS OUT MY PERSONAL EDUCATION PROFILE!!!
	cout << "Scripting and Programming - Applications C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID# 000695605" << endl;
	cout << "Benjamin Bruton" << endl;
	cout << endl;

	// PRINTS ALL RESULTS
	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printnumDays("A1");

	classRoster.printByDegree("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3");

}

// DECONSTRUCTOR
Roster::~Roster() {}