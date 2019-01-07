#pragma once
#include<iostream>
#include<string>
#include<algorithm>

#define ONCE 1

using namespace std;

class Item
{
public:
	Item(string, string, double);
	~Item();

	double totalPrice() const; //returns _count*_unitPrice
	bool operator <(const Item& other) const; //compares the _serialNumber of those items.
	bool operator >(const Item& other) const; //compares the _serialNumber of those items.
	bool operator ==(const Item& other) const; //compares the _serialNumber of those items.
	// getters & setters
	string getName();
	string getSerialNumber();
	int getCount();
	double getUnitPrice();
	void setName(string);
	void setSerialNumber(string);
	void setUnitNumber(double);
	void incCount();
	void decCount();

private:
	string _name;
	string _serialNumber; //consists of 5 numbers
	int _count; //default is 1, can never be less than 1!
	double _unitPrice; //always bigger than 0!

};