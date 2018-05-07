// CPS265_DVD_Store_BinarySearchTree_Itr_Incomplete.cpp : Defines the entry point for the console application.
//
//Dr. Saleh Alnaeli, Spring 2018

#include "stdafx.h"
#include "BinarySearchTreeTemplateIter.h"
#include "dvdType.h"
#include "customer.h"
#include <list> 
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

void createDVDList(ifstream& infile, LinkedBinarySearchTree<DvdType>& dvdList);
void createCustomerList(ifstream& infile, LinkedBinarySearchTree<CustomerType>& custList);
void displayMenu();
int main()
{
	//First: Creating dvd list (dvdList) and sending it to the function that fills it from the file

	//Missing code :(
	//.............


	//then, reading customers from the text file:--------------------------------------------------------
	LinkedBinarySearchTree<CustomerType> custList;  // tree of customers
	ifstream infile;
	infile.open("custDat.txt");
	if (!infile)
	{
		cout << "Input file does not exist" << endl;
		return 1;
	}
	// call the function to fill the tree from the file
	createCustomerList(infile, custList);
	infile.close();


	int choice;
	string title;
	int id;
	char discard;
	// show menu
	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
	cin.get(discard);
	cout << endl;

	while (choice != 10)
	{
		cout << " Choice: " << choice << endl;
		switch (choice)
		{
		case 1: {		}
				break;
		case 2: {		}

				break;
		case 3: {					}

				break;
		case 4: {
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;
			DvdType tempTargetDvD;
			tempTargetDvD.setDVDInfo(title, "", "", "", "", "", 0);
			LinkedBinarySearchTree<DvdType>::Iterator DvDIter = dvdList.find(tempTargetDvD);
			if (DvDIter == dvdList.end())
				cout << "No Movie with the title [" << title << "] was found :(\n";
			else {
				cout << "The Movie with the title [" << title << "] was found :)\n";
				if ((*DvDIter).getNoOfCopiesInStock() > 0) {
					//Missing code :(
					//.............
				}
				else
					cout << "Unfortunately, Out of stock" << endl;
			}
		}

				break;
		case 5: {				}
				break;
		case 6: {    			}
				break;
		case 7: {
			list<LinkedBinarySearchTree<CustomerType>::Iterator> LCustomers(custList.Iterators());
			for (list<LinkedBinarySearchTree<CustomerType>::Iterator>::iterator iter = LCustomers.begin(); iter != LCustomers.end(); ++iter) {
				cout << (*(*iter)) << " " << endl;
			}
		}
				break;
		case 8:
		{
			//Missing parts :(
			//.............

		}

		break;
		case 9:
		{					}

		break;
		default:
			cout << "Invalid selection." << endl;
		}

		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		cin.get(discard);
		cout << endl;
	}//end while
	return 0;
}
void createDVDList(ifstream& infile, LinkedBinarySearchTree<DvdType>& dvdList)
{
	//Missing parts :(
	//.............

}//end createDVDList

void createCustomerList(ifstream& infile, LinkedBinarySearchTree<CustomerType>& custList)
{
	//Missing parts :(
	//.............

}

void displayMenu()
{
	cout << "Select one of the following:" << endl;
	cout << "1: To check whether the store carries a "
		<< "particular DVD." << endl;
	cout << "2: To check out a DVD." << endl;
	cout << "3: To check in a DVD." << endl;
	cout << "4: To check whether a particular DVD is "
		<< "in stock." << endl;
	cout << "5: To print only the titles of all the DVDs." << endl;
	cout << "6: To print a list of all the DVDs." << endl;
	cout << "7: Print a list of customers." << endl;
	cout << "8: Print a list of DVDs rented by a customer." << endl;
	cout << "9: Print a list of all rented DVDs." << endl;
	cout << "10: To exit" << endl;
}
