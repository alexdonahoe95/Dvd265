
//************************************************************
// class DvdType
// This class specifies the members to implement a DVD. It
// overloads the stream insertion operator and relational 
// operators.
//************************************************************

#ifndef H_DvdType
#define H_DvdType
#include <iostream>
#include <string>

using namespace std;

class DvdType
{
	friend ostream& operator<< (ostream&, const DvdType&);

public:
	void setDVDInfo(string title, string star1,
		string star2, string producer,
		string director, string productionCo,
		int setInStock);
	//Function to set the details of a DVD. 
	//The member variables are set according to the 
	//parameters.
	//Postcondition: dvdTitle = title; movieStar1 = star1;
	//               movieStar2 = star2; 
	//               movieProducer = producer;
	//               movieDirector = director; 
	//               movieProductionCo = productionCo; 
	//               copiesInStock = setInStock;

	int getNoOfCopiesInStock() const;
	//Function to check the number of copies in stock. 
	//Postcondition: The value of copiesInStock is returned.

	void checkOut();
	//Function to rent a DVD. 
	//The number of copies in stock is decremented by one.
	//Postcondition: copiesInStock--;

	void checkIn();
	//Function to check in a DVD.
	//The number of copies in stock is incremented by one.
	//Postcondition: copiesInStock++;

	void printTitle() const;
	//Function to print the title of a movie.

	void printInfo() const;
	//Function to print the details of a DVD.
	//Postcondition: The title of the movie, stars, director,
	//               and so on are output on the screen.

	bool checkTitle(string title);
	//Function to check whether the title is the same as the
	//title of the DVD.
	//Postcondition: Returns the value true if the title is
	//               the same as the title of the DVD, and
	//               false otherwise.

	void updateInStock(int num);
	//Function to increment the number of copies in stock by
	//adding the value of the parameter num.
	//Postcondition: copiesInStock = copiesInStock + num;

	void setCopiesInStock(int num);
	//Function to set the number of copies in stock.
	//Postcondition: copiesInStock = num;

	string getTitle() const;
	//Function to return the title of the DVD.
	//Postcondition: The title of the DVD is returned.

	DvdType(string title = "", string star1 = "",
		string star2 = "", string producer = "",
		string director = "", string productionCo = "",
		int setInStock = 0);
	//Constructor
	//The member variables are set according to the incoming
	//parameters. If no values are specified, the default
	//values are assigned.
	//Postcondition: dvdTitle = title; movieStar1 = star1;
	//               movieStar2 = star2; 
	//               movieProducer = producer;
	//               movieDirector = director;
	//               movieProductionCo = productionCo;
	//               copiesInStock = setInStock;

	//Overload relational operators
	bool operator==(const DvdType&) const;
	bool operator!=(const DvdType&) const;
	bool operator<(const DvdType&) const;
	bool operator<=(const DvdType&) const;
	bool operator>(const DvdType&) const;
	bool operator>=(const DvdType&) const;

private:
	string dvdTitle;  //variable to store the name 
					  //of the movie
	string movieStar1;  //variable to store the name 
						//of the star
	string movieStar2;  //variable to store the name 
						//of the star 
	string movieProducer; //variable to store the name 
						  //of the producer 
	string movieDirector; //variable to store the name 
						  //of the director 
	string movieProductionCo; //variable to store the name
							  //of the production company 
	int copiesInStock;  //variable to store the number of 
						//copies in stock
};

#endif