//PersonTypeImp.cpp
#include "stdafx.h"
#include <iostream>
#include <string>
#include "PersonType.h"
 
using namespace std;

void PersonType::print() const
{
	cout << firstName << " " << lastName;
}

void PersonType::setName(string first, string last)
{
	firstName = first;
	lastName = last; 
}

string PersonType::getFirstName() const
{
	return firstName;
}

	//constructor with parameters
PersonType::PersonType(string first, string last) 

{ 
	firstName = first;
	lastName = last;
}


bool PersonType::operator==(const PersonType& right) const
{ 
	return(firstName == right.firstName &&
		   lastName == right.lastName);
}


bool PersonType::operator>(const PersonType& right) const
{
	return((lastName > right.lastName) ||
		   (lastName == right.lastName &&
		    firstName > right.firstName));
}
