#include "roster.h"
Roster::~Roster()
{   
    for(int i = 0; i < 5; i++) {
        // Deallocates pointer.
        delete classRosterArray[i];  
        // If instance is still in memory will make it clear the memory is gone.
        classRosterArray[i] = nullptr;
    }
}

void Roster::printAll()
{
    for(int i = 0; i < 5; i++) {
        // If classRosterArray element is present then print student data.
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
            cout << "\n";
        }
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{   
    // Create daysInCourse array from 3 variations of course data.
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    for(int i = 0; i < 5; i++) {
        // If we find an empty slot in array, then we create a student instance and set it in our classRosterArray.
        if (classRosterArray[i] == nullptr) {
            // Create new student from arguments including our daysInCourse array we just created.
            Student *student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
            classRosterArray[i] = student;
            return;
        }
    }

    return;
}

void Roster::remove(string studentId)
{
    for(int i = 0; i < 4; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentId) {
            // Deallocates pointer.
            delete classRosterArray[i];  
            // If instance is still in memory will make it clear the memory is gone.
            classRosterArray[i] = nullptr;
            return;  
        }
    }

    cout << "Student with ID: " << studentId << " was not found." << endl;
}



void Roster::printAverageDaysInCourse(string studentID)
{
    for(int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            cout << "Student " << classRosterArray[i]->getStudentId() << " has an average of  " << classRosterArray[i]->getAverageDaysInCourse() << " days per course for their remaining three courses." << endl;
            return;
        }
    }
    
    cout << "Student with " << studentID << "was not found." << endl;
}

void Roster::printInvalidEmails()
{
    bool notFound = true;
    for(int i = 0; i < 4; i++) {
        // If classRosterArray is present and has an invalid email
        // print that student's email address.
        if (classRosterArray[i] != nullptr) {
            if (!(classRosterArray[i]->validateEmailAddress())) {
                notFound = false;
                cout << classRosterArray[i]->getEmailAddress() << endl;
            }
        }
    }
    
    // Print message if we have no students with invalid emails.
    if (notFound) {
        cout << "All students have valid emails." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    bool notFound = true;
    for(int i = 0; i < 5; i++) {
        // If classRosterArray element is present and said student degree program
        // matches degreeProgram print that students data.
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            notFound = false;
            classRosterArray[i]->print();
            cout << "\n";
        }
    }

     // Print message if we have no students with matching degree program.
    if (notFound) {
        cout << "No students have matching degree program." << endl;
    }
}
