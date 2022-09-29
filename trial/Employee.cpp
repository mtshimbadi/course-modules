// Implementation file for the emoloyee class
#include "Employee.h"

// This constructor accepts argument for the employee's
// Name, Id Number, departement, position
Employee::Employee(string n, int id, string dept, string pos)
{
    name = n;
    idNumber = id;
    departement = dept;
    position = pos;
}

// This constructor accepts argument for the employee's
// name and id number. The departement and position 
// member variables are assigned empty strings
Employee::Employee(string n, int id)
{
    name = n;
    idNumber = id;
    departement = "";
    position = "";
}

// This default constructor assigned empty strings to
// name, The departement and position. Id number assignes 0
Employee::Employee ()
{
    name = "";
    idNumber = 0;
    departement = "";
    position = "";
}

// Mutator function for name
void Employee::setName(string n)
{
    name = n;
}

// Mutator function for id number
void Employee::setIdNumber(int id)
{
    idNumber = id;
}

// Mutator function for departement
void Employee::setDepartement(string dept)
{
    departement = dept;
}

// Accessors function for the name
string Employee::getName() const 
{
    return name;
}

// Accesors function for id number
int Employee::getIdNumber() const
{
    return idNumber;
}

// Accesors function for departement
string Employee::getDepartement() const
{
    return departement;
}

// Accesors function for the position
string Employee::getPosition() const
{
    return position;
}