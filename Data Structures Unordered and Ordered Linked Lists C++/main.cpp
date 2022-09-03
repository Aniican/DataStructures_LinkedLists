#include "unorderedLinkedList.h"
#include <iostream>
#include <cstdlib>
#include "customer.h"
// Author: Lane Murray
// Date: 10/20/2021
using namespace std;


void insertCustomer(linkedList<Customer>& list);
int compareInt(Customer item1, Customer item2);
int compareStr(Customer item1, Customer item2);


int main()
{
	string choice;
	unorderedLinkedList<Customer> list;

	insertCustomer(list); // Inserts a customer
    
	do // Loops until the user no longer wants to add customers.
	{
		cout << "Would you like to insert another customer? Y/N: ";
		cin >> choice;

		if (choice != "Y")
			break;

		insertCustomer(list);

	} while (choice == "Y");

	
	list.mergeSort(compareInt); // Calls the mergeSort function and sends it the compareInt function.
	list.mergeSort(compareStr); // Calls the mergeSort function and sends it the compareStr function.

	return 0;
}

void insertCustomer(linkedList<Customer>& list) // This is the function provided.
{
	int id;
	string name, address, phone, temp;
	Customer* x;

	cout << "Enter the customer id: ";
	cin >> id;
	while (!cin)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "The customer id should be a whole number." << endl;
		cout << "Enter the customer id: ";
		cin >> id;
	}

	cout << endl;
	cin.get();

	cout << "Enter the customer name (first and last): ";
	getline(cin, name);
	cout << endl;

	cout << "Enter " << name << "'s street address: ";
	getline(cin, temp);
	address = temp;
	cout << endl;

	cout << "Enter the city, state and zip code for the address: ";
	getline(cin, temp);
	address = address + "\n" + temp;
	cout << endl;

	cout << "Enter " << name << "'s phone number: ";
	getline(cin, phone);
	cout << endl;

	x = new Customer(id, name, address, phone);

	list.insertLast(*x);

	delete x;
}

int compareInt(Customer item1, Customer item2) // Compares customerIDs.
{
	if (item1.customerID < item2.customerID)
		return 1;
	else
		return 0;
}

int compareStr(Customer item1, Customer item2) // Compares names.
{
	if (item1.name < item2.name)
		return 1;
	else
		return 0;
}