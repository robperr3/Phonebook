#include <iostream>
#include <iomanip>
#include "Contacts.h"

using namespace std;

//Here is the constructors w/ the basic data members inlcuded 
Contact::Contact() {};
Contact::Contact(string FN, string LN, string P) {
	Firstname = FN;
	Lastname = LN;
	phone = P;
}
string Contact::GetFirstname() {//defining methods that will return data members of objects
	return Firstname;
}
string Contact::GetLastname() {
	return Lastname;
}
string Contact::Getnumber() {
	return phone;
}
void Contact::SetFirstname(string FN) {//defining methods that set members as string passed as argument
	Firstname = FN;
}
void Contact::SetLastname(string LN) {
	Lastname = LN;
}
void Contact::Setnumber(string P) {
	phone = P;
}

Friend::Friend() {}
Friend::Friend(string FN, string LN, string P, int A) {
	Firstname = FN;
	Lastname = LN;
	phone = P;
	age = A;
}
void Friend::SetAge(int A) {//defining new methods 
	age = A;
}
int Friend::GetAge() {
	return age;
}

Family::Family() {}
Family::Family(string FN, string LN, string P, string BD) {
	Firstname = FN;
	Lastname = LN;
	phone = P;
	birthday = BD;
}
void Family::Setbirthday(string BD) {
	birthday = BD;
}
string Family::Getbirthday() {
	return birthday;
}

Coworker::Coworker() {}
Coworker::Coworker(string FN, string LN, string P, string D) {
	Firstname = FN;
	Lastname = LN;
	phone = P;
	department = D;
}

void Coworker::SetDepartment(string D) {
	department = D;
}

string Coworker::GetDepartment() {
	return department;
}