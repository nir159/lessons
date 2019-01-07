#include"Customer.h"
#include<map>

#define STOP 0
#define ADD 1
#define INDEX 1
#define NEW_CUSTOMER 1
#define UPDATE_CUSTOMER 2
#define DELETE 2
#define MOST_EXPENSIVE 3
#define BACK 3
#define EXIT 4
#define MAX 10

int getInput() {
	int choise;
	while (!(cin >> choise)) {
		cout << "Bad value! Try again:" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choise;
}

int getLimitInput(int min, int max) {
	int choise;
	choise = getInput();
	while (choise < min || choise > max) {
		cout << "Number not in range, Try again" << endl;
		choise = getInput();
	}
	return choise;
}

int mainMenu() {
	int choise = 0;
	cout << "Welcome to MagshiMart!\n1.\tto sign as customer and buy items\n2.\tto uptade existing customer's items\n3.\tto print the customer who pays the most\n4.\tto exit" << endl;
	choise = getLimitInput(NEW_CUSTOMER, EXIT);
	return choise;
}

int main()
{
	string customer;
	int choise = 0;
	float maxSum = 0;
	map<string, Customer>::iterator mapIt;
	map<string, Customer> abcCustomers;
	set<Item>::iterator setIt;
	set<Item> items;
	Item itemList[10] = {
		Item("Milk","00001",5.3),
		Item("Cookies","00002",12.6),
		Item("bread","00003",8.9),
		Item("chocolate","00004",7.0),
		Item("cheese","00005",15.3),
		Item("rice","00006",6.2),
		Item("fish", "00008", 31.65),
		Item("chicken","00007",25.99),
		Item("cucumber","00009",1.21),
		Item("tomato","00010",2.32) };
	choise = mainMenu();
	while (choise != EXIT) {
		switch (choise) {
		case NEW_CUSTOMER:
			cout << "Enter customer name: ";
			cin >> customer;
			if (abcCustomers.find(customer) != abcCustomers.end()) {
				cout << "Error. Customer exists!" << endl;
			}
			else {
				abcCustomers.insert(make_pair(customer, Customer(customer)));
				// items menu
				cout << "The items you can buy are : (0 to exit)\n1.\tMilk\tprice : 5.3\n2.\tCookies\tprice : 12.6\n3.\tBread\tprice : 8.9\n4.\tChoocolate\tprice : 7.0\n5.\tCheese\tprice : 15.3\n6.\tRice\tprice : 6.2\n7.\tFish\tprice : 31.65\n8.\tChicken\tprice : 25.99\n9.\tCucumber\tprice : 1.21\n10.\tTomato\tprice : 2.32\nWhat item would you like to buy? Input:";
				do {// gets items for current customer
					choise = getLimitInput(STOP, MAX);
					items = (*abcCustomers.find(customer)).second.getItems();
					if (choise != STOP) {
						if (items.find(itemList[choise - INDEX]) != items.end()) { // item exists
							(*abcCustomers.find(customer)).second.removeItem(itemList[choise - INDEX]);
							itemList[choise - INDEX].incCount();
							(*abcCustomers.find(customer)).second.addItem(itemList[choise - INDEX]);
						}
						else {
							(*abcCustomers.find(customer)).second.addItem(itemList[choise - INDEX]);
						}
					}
				} while (choise != STOP);
			}
			break;
		case UPDATE_CUSTOMER:
			cout << "Enter customer name: ";
			cin >> customer;
			if (abcCustomers.find(customer) != abcCustomers.end()) {
				do {
					cout << "1.\tAdd items\n2.\tRemove items\n3.\tBack to menu" << endl;
					choise = getLimitInput(INDEX, BACK);
					switch (choise) {
					case ADD:
						cout << "The items you can buy are : (0 to exit)\n1.\tMilk\tprice : 5.3\n2.\tCookies\tprice : 12.6\n3.\tBread\tprice : 8.9\n4.\tChoocolate\tprice : 7.0\n5.\tCheese\tprice : 15.3\n6.\tRice\tprice : 6.2\n7.\tFish\tprice : 31.65\n8.\tChicken\tprice : 25.99\n9.\tCucumber\tprice : 1.21\n10.\tTomato\tprice : 2.32\nWhat item would you like to buy? Input:";
						do {// gets items for current customer
							choise = getLimitInput(STOP, MAX);
							items = (*abcCustomers.find(customer)).second.getItems();
							if (choise != STOP) {
								if (items.find(itemList[choise - INDEX]) != items.end()) { // item exists
									(*abcCustomers.find(customer)).second.removeItem(itemList[choise - INDEX]);
									itemList[choise - INDEX].incCount();
									(*abcCustomers.find(customer)).second.addItem(itemList[choise - INDEX]);
								}
								else {
									(*abcCustomers.find(customer)).second.addItem(itemList[choise - INDEX]);
								}
							}
						} while (choise != STOP);
						break;
					case DELETE:
						items = (*abcCustomers.find(customer)).second.getItems();
						if (items.begin() == items.end()) {
							cout << "your cart is empty. Add some items!" << endl;
						}
						cout << "The items you can buy are : (0 to exit)\n1.\tMilk\tprice : 5.3\n2.\tCookies\tprice : 12.6\n3.\tBread\tprice : 8.9\n4.\tChoocolate\tprice : 7.0\n5.\tCheese\tprice : 15.3\n6.\tRice\tprice : 6.2\n7.\tFish\tprice : 31.65\n8.\tChicken\tprice : 25.99\n9.\tCucumber\tprice : 1.21\n10.\tTomato\tprice : 2.32\nWhat item would you like to remove? Input:";
						cout << endl << "Your current list is:" << endl;
						items = (*abcCustomers.find(customer)).second.getItems();
						for (setIt = items.begin(); setIt != items.end(); setIt++) {
							cout << "Item: " << ((Item)(*setIt)).getName() << " Count: " << ((Item)(*setIt)).getCount() << endl;
						}
						choise = getLimitInput(STOP, MAX);
						while (choise != STOP) {
							items = (*abcCustomers.find(customer)).second.getItems();
							if (items.find(itemList[choise - INDEX]) != items.end()) {
								if (itemList[choise - INDEX].getCount() != INDEX) { // more than one
									(*abcCustomers.find(customer)).second.removeItem(itemList[choise - INDEX]);
									itemList[choise - INDEX].decCount();
									(*abcCustomers.find(customer)).second.addItem(itemList[choise - INDEX]);
								}
								else {
									(*abcCustomers.find(customer)).second.removeItem(itemList[choise - INDEX]);
								}
							}
							else {
								cout << "item is not in your list" << endl;
							}
							choise = getLimitInput(STOP, MAX);
						}

					default:
						break;
					}
				} while (choise != BACK);
			}
			else {
				cout << "Error. Customer doesn't exists!" << endl;
			}
			break;
		case MOST_EXPENSIVE:
			if (abcCustomers.begin() == abcCustomers.end()) {
				cout << "no customers" << endl;
			}
			else {
				for (mapIt = abcCustomers.begin(); mapIt != abcCustomers.end(); mapIt++) {
					if ((*mapIt).second.totalSum() > maxSum) {
						maxSum = (*mapIt).second.totalSum();
					}
				}
				for (mapIt = abcCustomers.begin(); mapIt != abcCustomers.end(); mapIt++) {
					if ((*mapIt).second.totalSum() == maxSum) {
						cout << "most expensive customer is: " << (*mapIt).second.getName() << " his total sum is: " << (*mapIt).second.totalSum() << endl;
					}
				}
			}
			break;
		default:
			break;
		}
		choise = mainMenu();
	}
	system("PAUSE");
	return 0;
}