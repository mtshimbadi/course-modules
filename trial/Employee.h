// Specification file for the  Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private: 
    string name;           // The employee's name 
    int idNumber;          // IN Nemuber
    string departement;    // Departement name
    string position;       // job title

public: 
    // constructors
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();

    // Mutators
    void setName(string);
    void setIdNumber(int);
    void setDepartement(string);
    void setPosition(string );

    //Accessors
    string getName() const;
    int getIdNumber() const;
    string getDepartement() const;
    string getPosition() const;
    
};

#endif
