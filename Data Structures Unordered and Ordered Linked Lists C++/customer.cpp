// Auther: Lane Murray
// Date: 10/20/2021
#include <iostream>
#include <climits>
#include "customer.h"

using namespace std;

// constructors

Customer::Customer() 
{
	this->name = "";
	this->address = "";
	this->phoneNumber = "";
	this->customerID = 1;
}

Customer::Customer(int customerID, string name, string address, string phoneNumber) 
{
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->customerID = customerID;
}
// destructor
Customer::~Customer() {

}

void Customer::printInfo() // Output Customer Info.
{ 
	cout << "\nCustomer Info";
	cout << "\nID: " << this->customerID;
	cout << "\nName: " << this->name;
	cout << "\nAddress: " << this->address;
	cout << "\nPhone Number: " << this->phoneNumber;

}

bool Customer::operator==(int customerID) const 
{
	bool newID = false;

	if (customerID == this->customerID)
	{
		newID = true;
	}

	return newID;
}

bool Customer::operator!=(int customerID) const 
{
	bool newID = true;

	if (customerID != this->customerID)
	{
		newID = false;
	}

	return newID;
}