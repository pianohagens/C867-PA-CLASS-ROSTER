#pragma once
#include <iostream>
#include "degree.h"
using namespace std;

class student
{//D1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourseArray[3] = { 0,0,0 };
	DegreeProgram degProgram;

public:
	//Empty student class constructor
	student();

	//Fill parameters constructor
	student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseArray[3], DegreeProgram degreeProgram);

	//2a. an accessor (i.e., getter) for each instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourseArray();
	DegreeProgram getDegreeProgram();

	//2b.  a mutator (i.e., setter) for each instance variable from part D1
	void print();
	void setStudentID(string setStudentID);
	void setFirstName(string setFirstName);
	void setLastName(string setLastName);
	void setEmailAddress(string setEmailAddress);
	void setAge(int setAge);
	void setDaysInCourseArray(int daysInCourseArray[3]);
	void setDegreeProgram(DegreeProgram setDegreeProgram);

};

