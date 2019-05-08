#include <iostream>//This is a basic Phonebook program that allows you to save contacts and retrieve them later.
#include <string>//The program gives you the ability to save each contact in different categories like Friends, Family 
#include <vector>//& Coworker. It also allows you to search & find contacts by first name.
#include <ctype.h>
#include <iomanip>
#include "Contacts.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>


using namespace std;
using namespace boost::algorithm;//using boost library string algorithm
//creating parent class called Contact


void main()
{//creating variables specifically for user input of the menu
	int x;
	int age;
	char y;
	string bday;//variables for the many data members of the different classes
	string number;
	string name;
	string surname;
	string dept;
	vector<Contact>v1;//these vectors will hold every instantiation of their associated class that's created
	vector<Friend>v2;
	vector<Family>v3;
	vector<Coworker>v4;
	Contact *c1;//pointers for each class 
	Friend *fr1;
	Family *fam1;
	Coworker *cw1;

	do//do at least once
	{//Introduction text welcoming the user to the program. 
		cout << "\n\nWelcome to your new Contacts App!" << endl;
		cout << "This program will help you organize and retrieve your list of friends and family!" << endl;
		cout << "You can create new contacts and save them in specifc contact groups or search for a current contact.\n\n" << endl;
		cout << "What would you like to do?\n" << endl;//menu asking the user what they would like to do
		cout << "1. Create a contact" << endl;
		cout << "2. Find a contact" << endl;
		cout << "3. Quit" << endl;
		cin >> x;

		if (x == 1)//if user chooses to create contact 
		{
			cout << "\nWhat kind of contact would you like to make?\n" << endl;
			cout << "a. Regular Contact" << endl;//user picks which kind of contact they want to create
			cout << "b. Friend" << endl;
			cout << "c. Family" << endl;
			cout << "d. Coworker" << endl;
			cin >> y;
			if (y == 'a')//if user chooses Contact
			{//take in inputs
				cout << "\nPlease enter first name:" << endl;
				cin >> name;
				cout << "\nPlease enter surname:" << endl;
				cin >> surname;
				cout << "\nPlease enter 10-digit phone number (like this (###)-###-####):" << endl;
				cin >> number;
				//create new Contact object
				c1 = new Contact;
				c1->SetFirstname(name);
				c1->SetLastname(surname);
				c1->Setnumber(number);
				v1.push_back(*c1);//add newly created object to vector of Contact class
				//creating an iterator for Contact vector
				vector<Contact>::iterator it;
				for (it = v1.begin(); it != v1.end(); ++it) {//for every index of Contact vector
					cout << "\nHere's your new contact:\n\n" << it->GetFirstname() << " " << it->GetLastname() << endl;
					cout << "phone: " << it->Getnumber() << "\n" << endl;//print out object's data members
				}
			}


			if (y == 'b')//if user chooses Friend
			{//take in inputs 
				cout << "\nPlease enter first name:" << endl;
				cin >> name;
				cout << "\nPlease enter surname:" << endl;
				cin >> surname;
				cout << "\nPlease enter 10-digit phone number (like this (###)-###-###):" << endl;
				cin >> number;
				cout << "\nPlease enter their age:" << endl;
				cin >> age;
				if (cin.fail()) {//Error-Handling:if input doesnt fit variable type expected
					cin.clear();
					cin.ignore();
					cout << "Invalid entry! Try again" << endl;//print message
					continue;//and jump to the end of loop
				}
				//create new Friend object
				fr1 = new Friend;
				fr1->SetFirstname(name);
				fr1->SetLastname(surname);
				fr1->Setnumber(number);
				fr1->SetAge(age);
				v2.push_back(*fr1);//add newly created object to vector of Friend class
				//creating iterator for Friend vector
				vector<Friend>::iterator it;
				for (it = v2.begin(); it != v2.end(); ++it) {//for every object of friend vector 
					cout << "\nHere's your new contact:\n\n" << it->GetFirstname() << " " << it->GetLastname() << endl;
					cout << "phone: " << it->Getnumber() << "\n" << "Age: " << it->GetAge() << endl;
				}//print out object's data members
			}

			if (y == 'c')//if user chooses Family
			{//take inputted data
				cout << "\nPlease enter first name:" << endl;
				cin >> name;
				cout << "\nPlease enter surname:" << endl;
				cin >> surname;
				cout << "\nPlease enter 10-digit phone number (like this (###)-###-###):" << endl;
				cin >> number;
				cout << "\nPlease enter their birthday. (like this MM DD YYYY):" << endl;
				cin.clear();//clears any error flags so future io opertations work correctly
				cin.ignore();//clears the buffer of any chars from the last cin and will stop at the next \n
				getline(cin, bday);//using getline because cin only works until the first space character
				//creating a new object of Family class
				fam1 = new Family;
				fam1->SetFirstname(name);
				fam1->SetLastname(surname);
				fam1->Setnumber(number);//using boost string algorithm to replace space in user input 
				fam1->Setbirthday(replace_all_copy(bday, " ", "/"));//with "/" for birthday
				v3.push_back(*fam1);//add new object to Family vector
				//creating iterator for Family vector
				vector<Family>::iterator it;
				for (it = v3.begin(); it != v3.end(); ++it) {//for every object of Family vector
					cout << "\nHere's your new contact:\n\n" << it->GetFirstname() << " " << it->GetLastname() << endl;
					cout << "phone: " << it->Getnumber() << "\n" << "Birthday: " << it->Getbirthday() << endl;
				}//print out object's data members
			}

			if (y == 'd')//if user chooses Coworker
			{//take in inputted data
				cout << "\nPlease enter first name:" << endl;
				cin >> name;
				cout << "\nPlease enter surname:" << endl;
				cin >> surname;
				cout << "\nPlease enter 10 digit phone number (like this (###)-###-###):" << endl;
				cin >> number;
				cout << "\nPlease enter their department:" << endl;
				cin >> dept;
				//creating new object of Coworker class
				cw1 = new Coworker;
				cw1->SetFirstname(name);
				cw1->SetLastname(surname);
				cw1->Setnumber(number);
				cw1->SetDepartment(dept);
				v4.push_back(*cw1);//add new object to Cowrker vector
				//creating another iterator for Coworker vector
				vector<Coworker>::iterator it;
				for (it = v4.begin(); it != v4.end(); ++it) {//for every object of Coworker class
					cout << "\nHere's your new contact:\n\n" << it->GetFirstname() << " " << it->GetLastname() << endl;
					cout << "phone: " << it->Getnumber() << "\n" << "Department: " << it->GetDepartment() << endl;
				}//print out object's data members
			}
			if (isdigit(y)) { cout << "Invalid entry! Try again" << endl; }
		}

		if (x == 2) {//if user chooses to search a contact 
			cout << "Please enter the first name of the contact:\n" << endl;
			cin >> name;
			//create new iterator
			vector<Contact>::iterator it1;
			for (it1 = v1.begin(); it1 != v1.end(); it1++) {//for every object of vector
				if (boost::iequals(name, it1->GetFirstname())) {//if inputted name is equal to First name of index
					cout << "\n" << it1->GetFirstname() << " " << it1->GetLastname() << endl;
					cout << "phone: " << it1->Getnumber() << "\n" << endl;//print that index's data
				}
			
			}
			//creating iterator for Friend vector
			vector<Friend>::iterator it2;
			for (it2 = v2.begin(); it2 != v2.end(); it2++) {
				if (boost::iequals(name, it2->GetFirstname())) {//if input is equal to first name of index
					cout << "\n" << it2->GetFirstname() << " " << it2->GetLastname() << endl;
					cout << "phone: " << it2->Getnumber() << "\nAge: " << it2->GetAge() << endl;
				}
				
			}
			//another iterator for Family vector
			vector<Family>::iterator it3;
			for (it3 = v3.begin(); it3 != v3.end(); it3++) {
				if (boost::iequals(name, it3->GetFirstname())) {
					cout << "\n" << it3->GetFirstname() << " " << it3->GetLastname() << endl;
					cout << "phone: " << it3->Getnumber() << "\nBirthday: " << it3->Getbirthday() << endl;
				}
				
			}
			//last iterator for Coworker vector
			vector<Coworker>::iterator it4;
			for (it4 = v4.begin(); it4 != v4.end(); it4++) {
				if (boost::iequals(name, it4->GetFirstname())) {
					cout << "\n" << it4->GetFirstname() << " " << it4->GetLastname() << endl;
					cout << "phone: " << it4->Getnumber() << "\nDepartment: " << it4->GetDepartment() << endl;
				}
			}
		}

		if (x > 3) { cout << "Invalid entry! Try again" << endl; }


	} while (x != 3);//all this done as long as user input is not 3
	system("pause");
}