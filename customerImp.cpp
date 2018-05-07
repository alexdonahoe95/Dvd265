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
}
//default constructor
CustomerType::CustomerType()
{
	custAcctNo = 0;
}

bool CustomerType::operator==(const CustomerType& right) const
{
	return(custAcctNo == right.custAcctNo);
}



//Missing parts :(
//.............
