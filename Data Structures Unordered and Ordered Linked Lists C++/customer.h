#pragma once
// Auther: Lane Murray
// Date: 10/20/2021
#include <iostream>
#include <string>
#include <climits>
#include "linkedListIterator.h"
using namespace std;

class Customer 
{
public:
	string name;
	string address;
	string phoneNumber;
	int customerID;

	// constructor
	Customer();
	Customer(int customerID, string name, string address, string phoneNumber);
	// destructor
	~Customer();

	void printInfo();
	bool operator==(int customerID) const;
	bool operator!=(int customerID) const;
};