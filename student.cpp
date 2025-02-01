#include "student.h"

// Constructor. 
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    studentId_ = studentId;
    firstName_ = firstName;
    lastName_ = lastName;
    emailAddress_ = emailAddress;
    age_ = age;
    degreeProgram_ = degreeProgram;
    
    // Set daysInCourse 
    // Copy array elements individually
    for (int i = 0; i < 3; i++) {
        daysInCourse_[i] = daysInCourse[i];
    }
}

// Deconstructor.
Student::~Student()
{
}

// returns student id.
string Student::getStudentId()
{
    return studentId_;
}

// Returns first name.
string Student::getFirstName()
{
    return firstName_;
}

// Returns last name.
string Student::getLastName()
{
    return lastName_;
}

// returns email address. 
string Student::getEmailAddress()
{
    return emailAddress_;
}

// returns age. 
int Student::getAge()
{
    return age_;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram_;
}

// returns days in course data.
int *Student::getDaysInCourse()
{
    return daysInCourse_;
}

// Sets student id.
void Student::setStudentId(string studentId)
{
    studentId_ = studentId;
}

// Sets first name.
void Student::setFirstName(string firstName)
{
    firstName_ = firstName;
}

// Sets last name.
void Student::setLastName(string lastName)
{
    lastName_ = lastName;
}

// Sets email address.
void Student::setEmailAddress(string emailAddress)
{
    emailAddress_ = emailAddress;
}

// Sets age. 
void Student::setAge(int age)
{
    age_ = age;
}

// Sets degree progream.
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    degreeProgram_ = degreeProgram;
}

// Prints student data. 
void Student::print()
{
    cout << getStudentId() << "\t";
    cout << getFirstName() << "\t";
    cout << getLastName() << "\t";
    cout << getEmailAddress() << "\t";
    cout << getAge() << "\t";
    cout << "{" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1]  << ", " << getDaysInCourse()[2] << "}" << "\t";
    cout << degreePrograms[static_cast<int>(getDegreeProgram())];
}

// Validates an email address.
// Requirements to be valid:
// 1. No " " are present anywhere in the email address.
// 2. We need an @ symbole to be present.
// 3. We want a . to be present after the @ symbol.
bool Student::validateEmailAddress()
{
    bool hasAtSymbol = false;
    bool hasPeriodAfterAt = false;

    for (char c : emailAddress_) {
        // Invalidate email if we find a " ".
        if (c == ' ') {
            return false;
        }
        
        if (c == '@') {
            hasAtSymbol = true;
        }
        
        // We want an @ symbol and we want the . to appear afterwards
        // to consider an email address to be valid.
        if (hasAtSymbol && c == '.') {
            hasPeriodAfterAt = true;
        }
    }

    // Return bool based on @ symbol and period proceeding
    // @ symbol.
    return hasAtSymbol && hasPeriodAfterAt;
}

float Student::getAverageDaysInCourse()
{
    int sum = 0;
    for (int i = 0; i < 3; i++) {
		sum = sum + daysInCourse_[i];
	}
    return static_cast<float>(sum) / static_cast<float>(3);
}
