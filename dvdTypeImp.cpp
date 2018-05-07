#include "stdafx.h"
#include <iostream>
#include <string>
#include "DvdType.h"


using namespace std;

DvdType::DvdType(string title, string star1,
	string star2, string producer,
	string director,
	string productionCo, int setInStock)
{
	setDVDInfo(title, star1, star2, producer, director,
		productionCo, setInStock);
}

//Missing parts :(
//.............
void DvdType::setDVDInfo(string title, string star1, string star2, string producer,
		string director, string productionCo, int setInStock) 
{
	//Set values
	this->dvdTitle = title;
	this->movieStar1 = star1;
	this->movieStar2 = star2;
	this->movieProducer = producer;
	this->movieDirector = director;
	this->movieProductionCo = productionCo;
	this->copiesInStock = setInStock;

	//Values Updated.
}

int DvdType::getNoOfCopiesInStock() const
{
	return this->copiesInStock;
}

void DvdType::checkOut() {
	copiesInStock--;
}

void DvdType::checkIn() {
	copiesInStock++;
}

void DvdType::printTitle() const {
	cout << this->dvdTitle << endl;
}

void DvdType::printInfo() const {
	cout << this;
}

bool DvdType::checkTitle(string title) {
	return (this->dvdTitle == title);
}

void DvdType::updateInStock(int num) {
	this->copiesInStock = this->copiesInStock + num;
}

void DvdType::setCopiesInStock(int num) {
	this->copiesInStock = num;
}

string DvdType::getTitle() const {
	return this->dvdTitle;
}


//overloading the insertion operator
ostream& operator<< (ostream& osObject, const DvdType& dvd)
{
	osObject << endl;
	osObject << "DVD Title: " << dvd.dvdTitle << endl;
	osObject << "Stars: " << dvd.movieStar1 << " and "
		<< dvd.movieStar2 << endl;
	osObject << "Producer: " << dvd.movieProducer << endl;
	osObject << "Director: " << dvd.movieDirector << endl;
	osObject << "Production Company: "
		<< dvd.movieProductionCo << endl;
	osObject << "Copies in stock: " << dvd.copiesInStock
		<< endl;
	osObject << "_____________________________________"
		<< endl;

	return osObject;
}

bool DvdType::operator==(const DvdType& cmpare) const
{
	return (dvdTitle == cmpare.getTitle());
}
bool DvdType::operator!=(const DvdType& cmpare) const
{
	return (dvdTitle != cmpare.getTitle());
}

bool DvdType::operator>(const DvdType& rhs) const
{
	if (dvdTitle.compare(rhs.getTitle()) > 0) return true;
	return false;
}
bool DvdType::operator<(const DvdType& rhs) const
{
	if (dvdTitle.compare(rhs.getTitle()) < 0) return true;
	return false;
}
bool DvdType::operator<=(const DvdType& rhs) const
{
	if (dvdTitle.compare(rhs.getTitle()) <= 0) return true;
	return false;
}
bool DvdType::operator>=(const DvdType& rhs) const
{
	if (dvdTitle.compare(rhs.getTitle()) >= 0) return true;
	return false;
}
