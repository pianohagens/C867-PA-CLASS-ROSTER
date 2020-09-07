//D1. Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
#include "student.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using namespace std;

//2c.using accessorand mutator functions.
student::student() {
	//Creat a empty constructor.
	setStudentID("");
	setFirstName("");
	setLastName("");
	setEmailAddress("");
	int setAge(0);
	int setDaysInCourseArray[3] = { 0,0,0 };
	setDegreeProgram(SOFTWARE);
}
//2d.constructor using all of the input parameters provided in the table
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseArray[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourseArray[0] = daysInCourseArray[0];
	this->daysInCourseArray[1] = daysInCourseArray[1];
	this->daysInCourseArray[2] = daysInCourseArray[2];
	this->degProgram = degreeProgram;
}
//2e.print() to print all student data
void student::print()
{
	//cout << fixed;
	cout << "\t" << studentID;
	cout << "\t" << "First Name: " << firstName;
	cout << "\t" << "Last Name: " << lastName;
	cout << "\t" << "Email: " << emailAddress;
	cout << "\t" << "Age: " << age;
	cout << "\t" << "Days in Course: " << daysInCourseArray[0] << ", " << daysInCourseArray[1] << ", " << daysInCourseArray[2];

	switch (this->degProgram)
	{
	case SECURITY: cout << " SECURITY  ";
		break;
	case NETWORK: cout << " NETWORK  ";
		break;
	case SOFTWARE: cout << " SOFTWARE  ";
		break;
	}
	cout << endl;
	return;
}
//2c.All external access and changes to any instance variables of the Student class must be done using accessorand mutator functions.
void student::setStudentID(string setStudentID)
{
	this->studentID = setStudentID;
	return;
}
void student::setFirstName(string setFirstName)
{
	this->firstName = setFirstName;
	return;
}
void student::setLastName(string setLastName)
{
	this->lastName = setLastName;
	return;
}
void student::setEmailAddress(string setEmailAddress)
{
	this->emailAddress = setEmailAddress;
	return;
}
void student::setAge(int setAge)
{
	this->age = setAge;
	return;
}
void student::setDaysInCourseArray(int setDaysInCourseArray[3])
{
	this->daysInCourseArray[0] = daysInCourseArray[0];
	this->daysInCourseArray[1] = daysInCourseArray[1];
	this->daysInCourseArray[2] = daysInCourseArray[2];
	return;
}
void student::setDegreeProgram(DegreeProgram setDegreeProgram)
{
	this->degProgram = setDegreeProgram;
	return;
}
//2d.constructor using all of the input parameters provided in the table
string student::getStudentID()
{
	return studentID;
}
string student::getFirstName()
{
	return firstName;
}
string student::getLastName()
{
	return lastName;
}
string student::getEmailAddress()
{
	return emailAddress;
}
int student::getAge()
{
	return age;
}
int* student::getDaysInCourseArray()
{
	return daysInCourseArray;
}
DegreeProgram student::getDegreeProgram()
{
	return degProgram;
}










