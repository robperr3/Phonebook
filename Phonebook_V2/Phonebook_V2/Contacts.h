#pragma once
#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>

using namespace std;

class Contact {
public:
	Contact();
	Contact(string FN, string LN, string P);
	void SetFirstname(string);//class methods that set the data members of the class
	void SetLastname(string);
	void Setnumber(string);
	string GetFirstname();//methods that return data members 
	string GetLastname();
	string Getnumber();

protected://encapsulation: used protected so child classes can inherit/use these data members
	string Firstname;
	string Lastname;
	string phone;
};


//creating child class called Friend
class Friend : public Contact {//inheriting parent class public data
public:
	Friend();
	Friend(string FN, string LN, string P, int A);
	void SetAge(int);//creating new methods for Firend to get & set Age
	int GetAge();
private:
	int age;
};


//creating another derived class called Family
class Family : public Contact {
public:
	Family();
	Family(string FN, string LN, string P, string BD);
	void Setbirthday(string BD);//creating new methods for birthday string
	string Getbirthday();
private:
	string birthday;
};


//Yay, more derived classes!
class Coworker : public Contact {
public:
	Coworker();
	Coworker(string FN, string LN, string P, string D);
	void SetDepartment(string);
	string GetDepartment();
private:
	string phone;
	string department;//adding department member for coworker class
};



#endif
