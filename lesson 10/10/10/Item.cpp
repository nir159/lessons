#include "Item.h"

// ctors
Item::Item(string name, string serialNumber, double unitPrice) : _name(name), _serialNumber(serialNumber), _unitPrice(unitPrice), _count(ONCE){ }
Item::~Item() { }

// Returns the total price of this item
double Item::totalPrice() const {
	return _count*_unitPrice;
}

// Function overload
bool Item::operator <(const Item& other) const {
	if (_serialNumber < other._serialNumber) {
		return true;
	}
	return false;
}
bool Item::operator >(const Item& other) const {
	if (_serialNumber > other._serialNumber) {
		return true;
	}
	return false;
}
bool Item::operator ==(const Item& other) const {
	if (_serialNumber == other._serialNumber) {
		return true;
	}
	return false;
}

// getters & setters
string Item::getName() {
	return _name;
}

string Item::getSerialNumber() {
	return _serialNumber;
}

int  Item::getCount() {
	return _count;
}

double Item::getUnitPrice() {
	return _unitPrice;
}

void Item::setName(string newName) {
	_name = newName;
}

void Item::setSerialNumber(string newSerialNumber) {
	_serialNumber = newSerialNumber;
}

void Item::setUnitNumber(double newUnitNumber) {
	if (newUnitNumber <= 0) {
		cout << "Unit price can't be 0 or negative" << endl;
	}
	else {
		_unitPrice = newUnitNumber;
	}
}

void Item::incCount() {
	_count++;
}

void Item::decCount() {
	_count--;
}