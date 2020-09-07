//E3.  class roster define the following functions :
#pragma once
#include "student.h"
#include <vector>
using namespace std;

class roster
{
	//E2a.Parse each set of data identified in the “studentData Table.”
public:
	//Creat an empty constructor
	roster();

	////Fa.  public void add(string studentIDe2....
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	//Fb.  public void remove(string studentID)....
	void printRemove(string studentID);

	//Fc. public void printAll() that prints a complete tab...
	void printAll();

	//Fd.  public void printAverageDaysInCourse(string studentID)....
	void printAverageDaysInCourses(string studentID);

	//Fe.  public void printInvalidEmails() ...
	void printInvalidEmail();

	//Ff.  public void printByDegreeProgram ...
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int getRosterSize();
	student* getStudentPointer(int indexRoster);

	~roster(); //destructor

	DegreeProgram strToDegree(const std::string& str);
	string degreeToStr(DegreeProgram degProgram);

	//E2b.Add each student object to classRosterArray.
private:

	vector<student*> classRosterArray;
	DegreeProgram parsedDegreeProgram = SOFTWARE;
	string parsedStudentID = "";
	string paresdFirstName = "";
	string paresdLastName = "";
	string paresdEmail = "";
	int parsedAge = 0;
	int parsedDayInCourse1 = 0;
	int parsedDayInCourse2 = 0;
	int parsedDayInCourse3 = 0;
};




