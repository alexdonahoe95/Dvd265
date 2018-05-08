// CPS265_DVD_Store_BinarySearchTree_Itr_Incomplete.cpp : Defines the entry point for the console application.
//
//Dr. Saleh Alnaeli, Spring 2018

#include "stdafx.h"
#include "BinarySearchTreeTemplateIter.h"
#include "dvdType.h"
#include "customer.h"
#include <list> 
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>  /*atoi*/
using namespace std;

void createDVDList(LinkedBinarySearchTree<DvdType>& dvdList);
void createCustomerList(LinkedBinarySearchTree<CustomerType>& custList);
void displayMenu();
int main()
{
    //First: Creating dvd list (dvdList) and sending it to the function that fills it from the file

    LinkedBinarySearchTree<DvdType> dvdList;  // tree of DVDs

     createDVDList(dvdList);
 

    //then, reading customers from the text file:--------------------------------------------------------
    LinkedBinarySearchTree<CustomerType> custList;  // tree of customers
    
 
    // call the function to fill the tree from the file
    createCustomerList(custList);
   


    int choice;
    string title;
    int id;
    char discard;
    // Initial Menu Render
    displayMenu();
    cout << "Enter choice: ";
    cin >> choice;
    cin.get(discard);
    cout << endl;
    
    while (choice != 10)
    {
        cout << " Choice: " << choice << endl;
        cout << "===========================================" << endl;
        cout << endl;

        switch (choice)
        {
        case 1: {
            //Check if store carries DVD
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;
            DvdType tempTargetDvD;
            tempTargetDvD.setDVDInfo(title, "", "", "", "", "", 0);
            LinkedBinarySearchTree<DvdType>::Iterator DvDIter = dvdList.find(tempTargetDvD.getTitle());
            if (DvDIter == dvdList.end())
                cout << "No Movie with the title [" << title << "] was found :(\n";
            else {
                cout << "The Movie with the title [" << title << "] was found :)\n";
            }
        }
                break;
        case 2: {
            cout << "Enter the title of the movie to checkout: ";
            getline(cin, title);
            cout << endl;
            DvdType tempTargetDvD;
            tempTargetDvD.setDVDInfo(title, "", "", "", "", "", 0);
            LinkedBinarySearchTree<DvdType>::Iterator DvDIter = dvdList.find(tempTargetDvD);
            if (DvDIter == dvdList.end())
                cout << "No Movie with the title [" << title << "] was found. \n";
            else {
                if ((*DvDIter).getNoOfCopiesInStock() > 0) {
                    cout << "Please enter account number to put movie under:";
                    cin >> id;
                    cout << endl;

                    //Generate temporary account to search BST.
                    CustomerType tempTargetCustomer;
                    tempTargetCustomer.setCustInfo("", "", id);

                    //Search for account number
                    LinkedBinarySearchTree<CustomerType>::Iterator custIter = custList.find(tempTargetCustomer);

                    //If results were found, check out.
                    if (custIter != custList.end())
                    {
                        //Customer was found

                        //Add DVD to customer's checked out list.

                        //Check out from DVD library.
                        (*DvDIter).checkOut();
                        (*custIter).rentDVD((*DvDIter).getTitle());
                    }
                    else {
                        cout << "Customer account number not found in database." << endl;
                    }





                }
                else
                    cout << "Out of stock, unable to checkout." << endl;
            }

        }
                break;
        case 3: {
            //Check In DVD
            
            cout << "Enter the title of the movie to checkin: ";
            getline(cin, title);
            cout << endl;
            DvdType tempTargetDvD;
            tempTargetDvD.setDVDInfo(title, "", "", "", "", "", 0);
            LinkedBinarySearchTree<DvdType>::Iterator DvDIter = dvdList.find(tempTargetDvD);
            if (DvDIter == dvdList.end())
                cout << "No Movie with the title [" << title << "] was found. \n";
            else {
                    cout << "Please enter account number to check in movie from:";
                    cin >> id;
                    cout << endl;

                    //Generate temporary account to search BST.
                    CustomerType tempTargetCustomer;
                    tempTargetCustomer.setCustInfo("", "", id);

                    //Search for account number
                    LinkedBinarySearchTree<CustomerType>::Iterator custIter = custList.find(tempTargetCustomer);

                    //If results were found, check out.
                    if (custIter != custList.end())
                    {
                        //Customer was found

                        //Add DVD to customer's checked out list.
                        if ((*custIter).getNoOfRentals() >= 1)
                            //Check out from DVD library.
                            (*DvDIter).checkIn();
                        else
                            cout << "Unable to check dvd in";
                    }
                    else {
                        cout << "Customer account number not found in database." << endl;
                    }
                    
                }
               

        }
                break;

        case 4: {
            //Check if DVD is in Stock
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
                    cout << "Copies available: " << (*DvDIter).getNoOfCopiesInStock() << endl;
                }
                else
                    cout << "Unfortunately, Out of stock" << endl;
            }

        }
                break;
        case 5: {
            //Print titles of all DVDs in system
            list<LinkedBinarySearchTree<DvdType>::Iterator> LDVD(dvdList.Iterators());
            for (list<LinkedBinarySearchTree<DvdType>::Iterator>::iterator iter = LDVD.begin(); iter != LDVD.end(); ++iter) {
                cout << (*(*iter)).getTitle() << endl;
            }
        }
                break;
        case 6: {
            //Print a list (full details) of DVDs.
            list<LinkedBinarySearchTree<DvdType>::Iterator> LDVD(dvdList.Iterators());
            for (list<LinkedBinarySearchTree<DvdType>::Iterator>::iterator iter = LDVD.begin(); iter != LDVD.end(); ++iter) {
                cout << (*(*iter)) << endl;
            }
        }
                break;
        case 7: {
            //Print List of customers.

            list<LinkedBinarySearchTree<CustomerType>::Iterator> LCustomers(custList.Iterators());
            for (list<LinkedBinarySearchTree<CustomerType>::Iterator>::iterator iter = LCustomers.begin(); iter != LCustomers.end(); iter++) {
                 cout << (*(*iter)) << " " << endl;
                }

        }
                break;
        case 8: {
            //Print DVDs rented by a customer
            int k;
            cout << "Please enter ID # of customer";
            cin >> k;
            CustomerType cust("", "", k);
            LinkedBinarySearchTree<CustomerType>::Iterator CustomerIter = custList.find(cust);
            if (CustomerIter != custList.end())
            {
                (*CustomerIter).printRentedDVD(); 
               
                break;
            }
            else {
                cout << "customer not found";// enjoy
                break;
            }

        }

                break;
        case 9: 
        {
            list<LinkedBinarySearchTree<CustomerType>::Iterator> LCustomers(custList.Iterators());
            for (list<LinkedBinarySearchTree<CustomerType>::Iterator>::iterator iter = LCustomers.begin(); iter != LCustomers.end(); iter++) {
                cout << (*(*iter)).getAcctNo() << endl;
                (*(*iter)).printRentedDVD();
            }
        }
        case 10:
        {
           
            break;
        }
        default:

            cout << "Invalid selection." << endl;
        }

        //Render Menu
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.get(discard);
        cout << endl;
    }//end while (If choice != 10)

     //Exit with normal status.
    return 0;
}

int getLineCount(ifstream& infile) {
    int lineCount = 0;
    string line;

    while (getline(infile, line)) {
        lineCount++;
    }

    infile.clear();

    return lineCount;
}

void createDVDList( LinkedBinarySearchTree<DvdType>& dvdList)
{
    ifstream infile("dvdDat.txt");

    //DVDDat.txt Schema (In Order)
    //Title 
    //Star 1
    //Star 2
    //Producer
    //Director
    //Production Company
    //Copies in stock

    int totalLines = 0;
        //= getLineCount(infile);
    //Used to determine if at EOF
    string test;
    int currentLine = 0;
    string dvdTitle;
    string star1;
    string star2;
    string movieProducer;
    string movieDirector;
    string movieProductionCo;
    int copiesInStock;
    DvdType *dvdInsert;


    while (currentLine < 35) {
        getline(infile, dvdTitle);
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, movieProducer);
        getline(infile, movieDirector);
        getline(infile, movieProductionCo);
        infile >> copiesInStock;
        getline(infile, test);
        currentLine += 6;
        dvdInsert = new DvdType(dvdTitle, star1, star2, movieProducer, movieDirector, movieProductionCo, copiesInStock);

        dvdList.insert(*dvdInsert);
    }

    infile.close();
}//end createDVDList

void createCustomerList(LinkedBinarySearchTree<CustomerType>& custList)
{
    string firstName;
    string lastName;
    int accountNumber = 0;
    string currentLine = " ";
    ifstream infile("custDat.txt");
    int x = 0;
    while (x < 6)
    {
   
    infile >> firstName;
    infile >> lastName;
    infile >> accountNumber;
    CustomerType *custInsert = new CustomerType(firstName, lastName, accountNumber);
    x++;
    custList.insert(*custInsert);
    }
    
    if (!infile)
    {
        cout << "Input file does not exist" << endl;
        return;
    }
    

    
      
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
