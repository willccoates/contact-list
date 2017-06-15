#include <iostream>
#include "phoneBook.h"
#include <vector>
#include <string>

using namespace std;

bool stringCompare(string s1, string s2)
{
	if (s1.size() == s2.size())
	{
		for (unsigned int i = 0; i < s1.size(); ++i)
		{
			if (s1.at(i) != s2.at(i))
				return false;
		}
		return true;
	}
	return false;
}



int main()
{
	vector<Phonebook> contactList;
	
	int trigger = 0;
	
	long long phoneNumber = 0;
	string firstN; 	
	string lastN; 			
	int streetAddress = 0;		
	string streetAddressName;	
	int apartmentNumber = 0;			
	string cityName;		
	string stateName;
	int zipCodeNum = 0;		
		
	cout << "Do you want to: \n (1)Add a contact \n (2)Update a contact \n (3)Quit \n";
	cin >> trigger;

	while(trigger == 1 || trigger == 2)
	{
		Phonebook *contact = new Phonebook;
		if (trigger == 1)
		{
			cout << "Enter phone number to be added(w/o '-'): ";
			cin >> phoneNumber;
			cin.clear();
			cout << endl;

			cout << "Enter First Name: ";
			cin >> firstN;
			cin.clear();

			cout << endl << "Enter Last Name: ";
			cin >> lastN;
			cin.clear();
			cout << endl;

			cout << "Enter your street address number: ";
			cin >> streetAddress;
			cin.ignore();

			cout << endl << "Enter your street name: ";
			getline(cin, streetAddressName);
			cin.clear();

			cout << endl << "Enter your apartment number(if applicable): ";
			cin >> apartmentNumber;
			cin.ignore();

			cout << endl << "Enter name of the city: ";
			getline(cin, cityName);
			cin.clear();

			cout << endl << "Enter the state name: ";
			cin >> stateName;
			cin.clear();

			cout << endl << "Enter the zipcode: ";
			cin >> zipCodeNum;
			cin.clear();
			cout << endl;


			contact->addPhoneNum(phoneNumber);
			contact->addName(firstN, lastN);
			contact->addAddress(streetAddress, streetAddressName, apartmentNumber, cityName, stateName, zipCodeNum);

			contact->printContact();

			contactList.push_back(*contact);
		}
		if (trigger == 2)
		{
			int updateTrigger = 0;
			cout << "What would you like to update: \n (1)Phone Number \n (2)Name \n (3)Address \n";
			cin >> updateTrigger;

			if (updateTrigger == 1)
			{
				//update phone number
				//introduce temp variable for old number
				//search for old number in vector
				//switch out old number for new number in vector
				long long tempPhonNum = 0;
				cout << "Enter old phone number: ";
				cin >> tempPhonNum;
				cout << "Enter new phone number: ";
				cin >> phoneNumber;

				for (unsigned int i = 0; i < contactList.size(); ++i)
				{
					if (contactList.at(i).getPhoneNum() == tempPhonNum)
					{
						contactList.at(i).addPhoneNum(phoneNumber);
						contactList.at(i).printContact();
					}
				}

				//contact->addPhoneNum(phoneNumber);
			}
			else if (updateTrigger == 2)
			{
				//update name
				//introduce temp variable for old name
				//search for old name in vector
				//switch out old name for new name in vector
				string tempFN;
				string tempLN;

				cout << "Enter old first name: ";
				cin >> tempFN;
				cout << endl << "Enter old last name: ";
				cin >> tempLN;


				cout << "Enter new first name: ";
				cin >> firstN;
				cout << endl << "Enter new last name: ";
				cin >> lastN;

				for (unsigned int i = 0; i < contactList.size(); ++i)
				{
					if (stringCompare(contactList.at(i).getFirstName(),tempFN))
					{
						if (stringCompare(contactList.at(i).getLastName(), tempLN))
						{
							contactList.at(i).addName(firstN, lastN);
							contactList.at(i).printContact();
						}
					}
				}

				contact->addName(firstN, lastN);
			}
			else if (updateTrigger == 3)
			{
				//update address
				//introduce temp variable for old address
				//search for old address in vector
				//switch out old address for new address in vector
				int tempStAddNum = 0;
				string tempStAddName;
				int tempAptNum = 0;
				string tempCity;
				string tempState;
				int tempZip = 0;

				cout << "Enter old address number: ";
				cin >> tempStAddNum;
				cin.ignore();
				cout << endl << "Enter old street address name: ";
				getline(cin,tempStAddName);
				cin.clear();
				cout << endl << "Enter old apartment number: ";
				cin >> tempAptNum;
				cin.ignore();
				cout << endl << "Enter old city name: ";
				getline(cin,tempCity);
				cin.clear();
				cout << endl << "Enter old state name: ";
				cin >> tempState;
				cin.clear();
				cout << endl << "Enter old zip code: " << endl;
				cin >> tempZip;
				cin.clear();

				cout << "Enter new address number: ";
				cin >> streetAddress;
				cin.ignore();
				cout << endl << "Enter new street address name: ";
				getline(cin,streetAddressName);
				cout << endl << "Enter new apartment number: ";
				cin >> apartmentNumber;
				cin.ignore();
				cout << endl << "Enter new city name: ";
				getline(cin,cityName);
				cin.ignore();
				cout << endl << "Enter new state name: ";
				getline(cin,stateName);
				cout << endl << "Enter new zip code: " << endl;
				cin >> zipCodeNum;

				for (unsigned int i = 0; i < contactList.size(); ++i)
				{
					if (contactList.at(i).getStreetAdd() == tempStAddNum)
					{
						if (stringCompare(contactList.at(i).getStreetName()/*add function here to get item*/, tempStAddName))
						{
							if (contactList.at(i).getAptNumber() == tempAptNum)
							{
								if (stringCompare(contactList.at(i).getCity()/*add function here to get item*/, tempCity))
								{
									if (stringCompare(contactList.at(i).getState()/*add function here to get item*/, tempState))
									{
										if (contactList.at(i).getZipCode() == tempZip)
										{
											contactList.at(i).addAddress(streetAddress, streetAddressName, apartmentNumber, cityName, stateName, zipCodeNum);
											contactList.at(i).printContact();
										}
									}
								}
							}
						}
					}
					else
					{
						cout << "Address not found!" << endl;
					}
				}

			}
			else
			{
				break;
			}
		}
		
		delete contact;
		cout << "Do you want to: \n (1)Add a contact \n (2)Update a contact \n (3)Quit \n";
		cin >> trigger;
	}
	cout << "Thank you for using the phone book! \n";
	return 0;
}



/*
idea to make this program better is to output entire vector to .txt file at the end of program.
when you start a new run, include previous .txt file but inputting all info from .txt file into vector at start.
this makes the contact list continous between runs and allows you to look up previous entries from previous runs.
*/

