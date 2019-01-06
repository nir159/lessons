#include "Customer.h"

// ctors
Customer::Customer(string name) : _name(name){ }
Customer::Customer() : _name("Default"){ }

//returns the total sum for payment
double Customer::totalSum() const {
	int sum = 0;
	set<Item>::iterator setIt;
	for (setIt = _items.begin(); setIt != _items.end(); ++setIt)
	{
		sum += (*setIt).totalPrice();
	}
	return sum;
}

//add item to the set
void Customer::addItem(Item item) {
	set<Item>::iterator setIt;
	for (setIt = _items.begin(); setIt != _items.end(); ++setIt)
	{
		if ((*setIt) == item) {
			item.incCount();
		}
	}
	_items.insert(item);
}

//remove item from the set
void Customer::removeItem(Item item) {
	_items.erase(item);
}

// getters & setters
string Customer::getName() {
	return _name;
}

set<Item> Customer::getItems() {
	return _items;
}

void Customer::setName(string name) {
	_name = name;
}
