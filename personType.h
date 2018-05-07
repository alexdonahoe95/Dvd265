
//PersonType.h

#ifndef H_PersonType
#define H_PersonType

#include <string>
 
using namespace std;

class PersonType
{
public:
    void print() const;
       //Function to output the first name and last name
       //in the form firstName lastName.
  
    void setName(string first, string last);
       //Function to set firstName and lastName according 
       //to the parameters.
       //Postcondition: firstName = first; lastName = last

    string getFirstName() const;
       //Function to return firstName and lastName via the 
       //parameters.
       //Postcondition: The value of firstName is returned.

    string getLastName() const;
       //Function to return firstName and lastName via the 
       //parameters.
       //Postcondition: The value of lastName is returned.

    PersonType(string first = "", string last = "");
       //Constructor
       //Sets firstName and lastName according to the parameters.
       //The default values of the parameters are empty strings.
       //Postcondition: firstName = first; lastName = last  

	bool operator==(const PersonType&) const;
	bool operator!=(const PersonType&) const;
	bool operator<=(const PersonType&) const;
	bool operator<(const PersonType&) const;
	bool operator>=(const PersonType&) const;
	bool operator>(const PersonType&) const;

 private:
    string firstName; //store the first name
    string lastName;  //store the last name
};

#endif