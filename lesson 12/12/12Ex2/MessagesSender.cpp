#include "MessagesSender.h"

//ctor, dtor
MessagesSender::MessagesSender() { }

MessagesSender::~MessagesSender(){ }

void MessagesSender::showMenu() {
	int choise = 0;
	std::string name;
	std::cout << "1.Sign in\n2.Sign out\n3.Connected users\n4.exit\nwhich option would you like: ";
	choise = SideFunctions::inputNum();
	while (choise < SIGNIN || choise > EXIT) {
		std::cout << "1 to 4" << std::endl;
		choise = SideFunctions::inputNum();
	}
	while (choise != EXIT) {
		switch (choise) {
		case SIGNIN:
			std::getline(std::cin, name);
			if (SideFunctions::vFind(loggedUsers, name)) {
				std::cout << "User already exists!" << std::endl;
			}
			else {
				loggedUsers.insert(loggedUsers.begin(), name);
			}
			break;
		case SIGNOUT:
			std::getline(std::cin, name);
			if (SideFunctions::vFind(loggedUsers, name)) {
				loggedUsers.erase(loggedUsers.begin() + SideFunctions::vFind(loggedUsers, name));
			}
			else {
				std::cout << "User doesn't exists!" << std::endl;
			}
			break;
		case CONNNECTED_USERS:
			std::cout << "The connected users are:" << std::endl;
			break;
		case EXIT:
		default:
		}
		std::cout << "1.Sign in\n2.Sign out\n3.Connected users\n4.exit\nwhich option would you like: ";
		choise = SideFunctions::inputNum();
		while (choise < SIGNIN || choise > EXIT) {
			std::cout << "1 to 4" << std::endl;
			choise = SideFunctions::inputNum();
		}
	}
}

void MessagesSender::readFile() {
	std::ifstream myfile("data.txt");
	std::ofstream clrFile;
	std::string line;
	if (myfile.is_open())
	{
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(60));
			// Reads the file
			while (!myfile.eof()) {
				std::getline(myfile, line);
				adminMessages.push(line);
			}
			// Clear the file from data
			clrFile.open("data.txt", std::ofstream::trunc);
			clrFile.close();
		}
		myfile.close();
	}
	else {
		// Error reading file
		exit(1); // the thread need to stop the process
	}
}

void MessagesSender::sendMessages() {
	std::ofstream myfile("output.txt", std::fstream::out);
	std::vector<std::string>::iterator it;
	std::string line;
	if (myfile.is_open())
	{
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(60));
			// Reads the file
			while (!adminMessages.empty())
			{
				line = adminMessages.front(); // gets line from file
				for (it = loggedUsers.begin(); it != loggedUsers.end(); ++it) { // loop over the users
					myfile >> *it >> ": " >> line >> std::endl;
				}
				adminMessages.pop();
			}
		}
		myfile.close();
	}
	else {
		// Error reading file
		exit(1); // the thread need to stop the process
	}
}