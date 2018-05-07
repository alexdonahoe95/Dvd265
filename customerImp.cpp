#include "stdafx.h"
#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

bool CustomerType::rentDVD(string title)
{
    LinkedBinarySearchTree<string>::Iterator CustomerIter = rentedDVDTree.find(title);
    if (CustomerIter != rentedDVDTree.end())
        return false;
    else {
        rentedDVDTree.insert(title); // enjoy
        return true;
    }
}

//constructor
CustomerType::CustomerType(string first, string last, int acctNo) :PersonType(first, last)
{
    custAcctNo = acctNo;
    firstName = first;
    lastName = last;
}
//default constructor
CustomerType::CustomerType()
{
    firstName = "first";
    lastName = "last";
    custAcctNo = 0;
}
void CustomerType::print()
{
    cout << "Customer Account Number " + getAcctNo();
    cout << "Name " + getFirstName() + getLastName();
}
//Output account number, first name, last name, and 
//number of rentals, in the form:
//acctNo firstName lastName noOfRentals
void CustomerType::setCustInfo(string first, string last, int acctNo)
{
   this->firstName = first;
   this->lastName = last;
   this->custAcctNo = acctNo;
}
//set firstName, lastName, and account number 
//according to the parameters
//firstName = first; lastName = last; 

bool CustomerType::returnDVD(string title)
{
    LinkedBinarySearchTree<string>::Iterator CustomerIter = rentedDVDTree.find(title);
    if (CustomerIter != rentedDVDTree.end())
        return false;
    else {
        rentedDVDTree.insert(title); // enjoy
        return true;
    }
}
//This function renturns a DVD to the customer

int CustomerType::getNoOfRentals()
{
    return rentedDVDTree.size();
}
//This function returns the number of
//DVDs rented by the customer.
int CustomerType::getAcctNo()
{
    return this->custAcctNo;
}
//This function returns the account number of
//the customer.
string CustomerType::getFirstName()
{
    return this->firstName;
}
string CustomerType::getLastName()
{
    return this->lastName;
}
void CustomerType::printRentedDVD()
{
    rentedDVDTree.levelWiseTravese();
}

bool CustomerType::operator==(const CustomerType& right) const
{
    return(custAcctNo == right.custAcctNo);
}

bool  CustomerType::operator!=(const CustomerType &right) const
{
    return(custAcctNo != right.custAcctNo);
}
bool  CustomerType::operator<=(const CustomerType &right) const
{
    return(custAcctNo <= right.custAcctNo);
}
bool  CustomerType::operator<(const CustomerType& right) const
{
    return(custAcctNo < right.custAcctNo);
}
bool  CustomerType::operator>=(const CustomerType &right) const
{
    return(custAcctNo >= right.custAcctNo);
}
bool  CustomerType::operator>(const CustomerType &right) const
{
    return(custAcctNo > right.custAcctNo);
}
ostream& operator<<(ostream& os, CustomerType& cus)
{
    os << cus.firstName + " " + cus.lastName + " Customer Account Number:" << cus.custAcctNo;
    return os;
}
//Missing parts :(
//.............
