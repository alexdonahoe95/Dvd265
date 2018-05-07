  //customer.h
#ifndef H_CustomerType
#define H_CustomerType

#include <iostream>
#include "PersonType.h"
#include <string>
#include "BinarySearchTreeTemplateIter.h"

using namespace std;

class CustomerType: public PersonType
{
   friend ostream& operator<<(ostream&,  CustomerType&);
	  //overload stream insertion operator
public:
	void print();
	  //Output account number, first name, last name, and 
	  //number of rentals, in the form:
	  //acctNo firstName lastName noOfRentals
	void setCustInfo(string first, string last, int acctNo);
	  //set firstName, lastName, and account number 
	  //according to the parameters
	  //firstName = first; lastName = last; 
	bool rentDVD(string);
	  //This function rents a DVD to the customer
	bool returnDVD(string);
	  //This function renturns a DVD to the customer

	int getNoOfRentals();
	  //This function returns the number of
	  //DVDs rented by the customer.
	int getAcctNo();
	  //This function returns the account number of
	  //the customer.
     string getFirstName();
     string getLastName();

	void printRentedDVD();

	CustomerType(string first, string last, int acctNo);
	  //constructor with parameters
	  //set firstName and lastName according to the parameters
	  //firstName = first; lastName = last;
  	CustomerType(); 
  	 //default constructor;
  	 //intialize firstName and lastName, and custAcctNo 
  	 //Postcondition: firstName = ""; lastName = "";
	 //		  custAcctNo = 0;

		//overload operators for comparisons 
	bool operator==(const CustomerType&) const;
	bool operator!=(const CustomerType&) const;
	bool operator<=(const CustomerType&) const;
	bool operator<(const CustomerType&) const;
	bool operator>=(const CustomerType&) const;
	bool operator>(const CustomerType&) const;
     
private:
    string firstName;
    string lastName;
	int custAcctNo; // store account number
	LinkedBinarySearchTree<string> rentedDVDTree;
};

#endif 
