#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>
using namespace std;


int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:
            {
                cout << "Student name: " << endl;
                string n;
                cin >> n;
                cout << "Age: " << endl;
                int a;
                cin >> a;
                studentList.emplace_back(n,a);
                /*Student s(n,a);
                studentList.push_back(s);*/
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                // Lisää uusi student StudentList vektoriin.
                break;
            }
            case 1:
            {
                for (auto & s : studentList){
                    cout << "student " << s.getName() << endl;
                }
                // Tulosta StudentList vektorin kaikkien opiskelijoiden
                // nimet.
                break;
            }
            case 2:
            {
                sort(studentList.begin(),studentList.end(), [](Student & a, Student & b){return a.getName() < b.getName();});
                for ( Student & s : studentList){
                    s.printStudentinfo();
                }
                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                break;
            }
            case 3:
            {
                sort(studentList.begin(),studentList.end(), [](Student & a, Student & b){return a.getAge() < b.getAge();});
                for ( Student & s : studentList){
                    s.printStudentinfo();
                }
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                break;
            }
            case 4:
            {
                cout << "Give student's name: " << endl;
                string StudentName;
                cin >> StudentName;
                auto it = find_if(studentList.begin(), studentList.end(), [StudentName](Student & a){return a.getName() == StudentName;});
                if (it != studentList.end()){
                    cout << "Student found: " << endl;
                    it->printStudentinfo();
                }
                else{
                    cout << "Student not found" << endl;
                }
                // Kysy käyttäjältä opiskelijan nimi
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
                // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                break;
            }
            default:
                cout<< "Wrong selection, stopping..."<<endl;
             break;
        }
    }
    while(selection < 5);

    return 0;
}
