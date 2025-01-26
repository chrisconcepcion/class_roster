// Student class is used by our Roster class to add, remove, gather data such as average course days remaining and
// print all students by degree(grouping).
// Roster also uses this class to find students with invalid emails.
#include <array>
#include <string>
#include "degree.h"
#include <iostream>
using std::string;
using std::cout;


class Student {
    public: 
        // Constructor
        Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
        
        // Destructor
        ~Student();

        // Getters
        string getStudentId();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        DegreeProgram getDegreeProgram();
        int* getDaysInCourse();

        // Setters
        void setStudentId(string studentId);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDegreeProgram(DegreeProgram degreeProgram);

        // Prints student data
        void print();

        bool validateEmailAddress();

        float getAverageDaysInCourse();

    private:
        string studentId_;
        string firstName_; 
        string lastName_; 
        string emailAddress_;
        int age_; 
        DegreeProgram degreeProgram_; 
        int daysInCourse_[3];
};