// Roster is essentially a class roster management class.
// Current functionality includes: 
// 1. Adding students to a class roster.
// 2. Removing students from a class roster.
// 3. Printing all student data for student who are in a class roster.
// 4. Prints emails for students who have invalid email addresses.
// 5. Collects students by degree(function argument) and prints those students data.
#include "student.h"
#include <iostream>
#include <array>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Roster {
    public:
        // Constructor
        Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

        // Deconstructor
        ~Roster();

        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        void remove(string studentId);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
    private:
};