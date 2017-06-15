#include "phoneBook.h"
#include <iostream>
#include <string>

using namespace std;

Phonebook::Phonebook()
:phoneNum(1111111111), firstName("test1"), lastName("test2"), streetAdd(12345), streetName("hello world"), aptNumber(0), city("test city"), state("CA"), zipCode(12345)
{}
void Phonebook::addPhoneNum(long long phnNum)
{
	phoneNum = phnNum;
}
void Phonebook::addName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}
void Phonebook::addAddress(int addressNum, string stName, int aptNum, string cityName, string stateName, int zip)
{
	streetAdd = addressNum;
	streetName = stName;	
	aptNumber = aptNum;			
	city = cityName;	
	state = stateName;
	zipCode = zip;			
}
long long Phonebook::getPhoneNum()
{
	return phoneNum;
}
string Phonebook::getFirstName()
{
	return firstName;
}
string Phonebook::getLastName()
{
	return lastName;
}
int Phonebook::getStreetAdd()
{
	return streetAdd;
}
string Phonebook::getStreetName()
{
	return streetName;
}
int Phonebook::getAptNumber()
{
	return aptNumber;
}
string Phonebook::getCity()
{
	return city;
}
string Phonebook::getState()
{
	return state;
}
int Phonebook::getZipCode()
{
	return zipCode;
}
void Phonebook::printContact()
{
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Phone Number: " << phoneNum << endl;
	cout << "Address: " << streetAdd << " " << streetName << " Apt#" << aptNumber << endl;
	cout << city << ", " << state << " " << zipCode << endl << endl;
}
