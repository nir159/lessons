#pragma once
#include"Item.h"
#include<set>

class Customer
{
public:
	Customer(string);
	Customer();
	double totalSum() const;//returns the total sum for payment
	void addItem(Item);//add item to the set
	void removeItem(Item);//remove item from the set
	// getters & setters
	string getName();
	set<Item> getItems();
	void setName(string);

private:
	string _name;
	set<Item> _items;
};