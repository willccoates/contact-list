#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

using namespace std;

class Phonebook
{
	private:
		long long phoneNum; 		//contact phone number
		
		string firstName; 	//contact first name
		string lastName; 	//contact last name
		
		int streetAdd;		//street address number
		string streetName;	//street name
		int aptNumber;			//apartment number
		string city;		//city
		string state;
		int zipCode;		//zip code
		
	public:
		Phonebook();
		void addPhoneNum(long long phnNum);
		void addName(string fName, string lName);
		void addAddress(int addressNum, string stName, int aptNum, string cityName, string stateName, int zip);
		
		long long getPhoneNum();
		string getFirstName();
		string getLastName();
		int getStreetAdd();
		string getStreetName();
		int getAptNumber();
		string getCity();
		string getState();
		int getZipCode();
		
		void printContact();
};
#endif