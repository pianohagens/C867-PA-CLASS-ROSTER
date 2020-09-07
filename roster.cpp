#include "roster.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

roster::roster()
{//E1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	   "A5,Piano,Hhagens,phhagen@wgu.edu    ,46,40,50,60,SOFTWARE"//this is myInfo

	};
	string lookstring;//creates a loop string that will be used to parse
	for (int i = 0; i < 5; i++)//cycles through each student in the student data array
	{
		lookstring = studentData[i];

		parsedStudentID = (lookstring.substr(0, lookstring.find(',')));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		paresdFirstName = (lookstring.substr(0, lookstring.find(',')));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		paresdLastName = (lookstring.substr(0, lookstring.find(',')));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		paresdEmail = (lookstring.substr(0, lookstring.find(',')));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		parsedAge = (stoi(lookstring.substr(0, lookstring.find(','))));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		parsedDayInCourse1 = (stoi(lookstring.substr(0, lookstring.find(','))));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		parsedDayInCourse2 = (stoi(lookstring.substr(0, lookstring.find(','))));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		parsedDayInCourse3 = (stoi(lookstring.substr(0, lookstring.find(','))));
		lookstring = lookstring.substr(lookstring.find(',') + 1);

		parsedDegreeProgram = (strToDegree(lookstring.substr(0)));


		//calls the add method with parsed values to Add each student object to classRosterArray. E2.b
		add(parsedStudentID, paresdFirstName, paresdLastName, paresdEmail, parsedAge, parsedDayInCourse1, parsedDayInCourse2, parsedDayInCourse3, parsedDegreeProgram);
	}
}
//E3a.  add, that sets the instance variables ...
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int myArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	student* newStudent = nullptr;
	newStudent = new student(studentID, firstName, lastName, emailAddress, age, myArray, degreeProgram);
	classRosterArray.push_back(newStudent);
}

//E3b If the student ID does not exist, the function prints an error message...
void roster::printRemove(string studentID)
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getStudentID() == studentID)
		{
			classRosterArray.erase(classRosterArray.begin() + i);
			return;
		}
	}

}

//E3c.that prints a complete tab-separated list of student data in the provided format:
void roster::printAll()
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray.at(i)->print();
	}
	cout << endl;
}
//E3d. correctly prints a student’s average number of days in the three courses. 
void roster::printAverageDaysInCourses(string studentID)
{
	int sumInCourseDays;
	int AverageDayInCourse;
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getStudentID() == studentID)
		{
			sumInCourseDays = classRosterArray.at(i)->getDaysInCourseArray()[0] + classRosterArray.at(i)->getDaysInCourseArray()[1] + classRosterArray.at(i)->getDaysInCourseArray()[2];
			AverageDayInCourse = sumInCourseDays / 3;

			cout << "  studentID " << studentID << "," << " average " << AverageDayInCourse << " days in a course" << endl;
		}
	}
}
//E3e.  public void printInvalidEmails() that verifies student email addresses
bool is_email_valid(const std::string& email)
{// get email pattern 
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	return std::regex_match(email, pattern);
};

void roster::printInvalidEmail()
{
	string theStudentEmail;
	for (int i = 0; i < 4; i++)
	{
		theStudentEmail = classRosterArray.at(i)->getEmailAddress();
		bool isValidEmail = is_email_valid(theStudentEmail);
		if (!isValidEmail)
		{

			if (theStudentEmail.find(' ') != -1)
			{
				cout << "  " << theStudentEmail << " - no spaces allowed." << endl;
			}
			else if (theStudentEmail.find('@') != 1)
			{
				cout << "  " << theStudentEmail << " - missing a period." << endl;
			}
			else if (theStudentEmail.find('.') != 1)
			{
				cout << "  " << theStudentEmail << " - missing an @ symbol." << endl;
			}

		}




	}
}
//E3f. printByDegreeProgram, that prints out student information for a degree program
void roster::printByDegreeProgram(DegreeProgram degreeProgram)
{

	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if ((classRosterArray.at(i)->getDegreeProgram()) == degreeProgram)
		{
			classRosterArray.at(i)->print();
		}
	}
}

int roster::getRosterSize()
{
	return classRosterArray.size();
}
//allows a pointer access to student
student* roster::getStudentPointer(int indexRoster)
{
	return classRosterArray[indexRoster];
}
roster::~roster()
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}
//define program degree
DegreeProgram roster::strToDegree(const std::string& str)
{
	if (str == "SECURITY") return SECURITY;
	else if (str == "NETWORK") return NETWORK;
	else if (str == "SOFTWARE") return SOFTWARE;
	else
	{
		return SOFTWARE;
	}
}
string roster::degreeToStr(DegreeProgram degProgram)
{
	if (degProgram == SECURITY) return "SECURITY";
	else if (degProgram == NETWORK) return "NETWORK";
	else if (degProgram == SOFTWARE) return "SOFTWARE";
	else
	{
		return "  ERROR, Invalid Degree";
	}
}