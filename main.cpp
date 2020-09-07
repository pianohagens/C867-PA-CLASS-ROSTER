// BakeRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "student.h"
#include <iostream>
#include "roster.h"

int main()
{   //F1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	std::cout << "  Course Title: C867_Scripting and Programming Applications\n  Programming Language: C++ \n  WGU Student ID: #000956040 \n  Name: Piano Hhagens\n\n";


	//F2.  Create an instance of the Roster class called classRoster.
    roster* classRoster = nullptr;//creates a roster pointer
    classRoster = new roster; //assigns roster pointer to new roster object

        //F3.  Add all student to classRoster.
         //print classRosterArray
    cout << "  Displaying All Students" << endl;
    cout << " -------------------------------------------------------------------------------------------------------------------------------------" << endl;

    classRoster->printAll(); //prints all students in the roster;

    cout << "\n  Displaying Invalid Emails " << endl;
    cout << " --------------------------------------------------------------------------------------------------------------------------------------" << endl;
    classRoster->printInvalidEmail();

    cout << "\n  Displaying Average Days In Courses " << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < classRoster->getRosterSize(); i++)
    {
        classRoster->printAverageDaysInCourses(classRoster->getStudentPointer(i)->getStudentID());
    }
    cout << "\n   Showing students in degree program: SOFTWARE" << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << "\n  Remove A3:  " << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    classRoster->printRemove("A3");
    classRoster->printByDegreeProgram(SOFTWARE);


    classRoster->printRemove("A3");
    cout << "\n  Remove A3 again: " << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    classRoster->printAll();

    cout << "\n  Student ID of A3 was not found \n" << endl;
    return 0;

}