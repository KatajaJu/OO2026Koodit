#include "student.h"
#include <iostream>

Student::Student(string n,int a) {
    Name = n;
    Age = a;
}

void Student::setAge(int a)
{
    Age = a;
}

void Student::setName(string n)
{
    Name = n;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentinfo()
{
    cout << "Student name: " << Name << " Age: " << Age << endl;
}
