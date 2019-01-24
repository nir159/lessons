#include "MessagesSender.h"

//ctor, dtor
MessagesSender::MessagesSender() { }

MessagesSender::~MessagesSender(){ }

void MessagesSender::showMenu() {
	int choise = 0;
	std::string name;
	std::cout << "1.Sign in\n2.Sign out\n3.Connected users\n4.exit\nwhich option would you like: ";
	choise = SideFunctions::inputNum();
	getchar(); // clears the enter
	while (choise < SIGNIN || choise > EXIT) {
		std::cout << "1 to 4" << std::endl;
		choise = SideFunctions::inputNum();
		getchar();
	}
	// presents menu
	while (choise != EXIT) {
		switch (choise) {
		case SIGNIN:
			std::cout << "Enter name: ";
			std::getline(std::cin, name);
			if (((int)SideFunctions::vFind(loggedUsers, name)) +1) {
				std::cout << "User already exists!" << std::endl;
			}
			else {
				vector.lock();
				loggedUsers.insert(loggedUsers.begin(), name);
				vector.unlock();
			}
			break;
		case SIGNOUT:
			std::cout << "Enter name: ";
			std::getline(std::cin, name);
			if (((int)SideFunctions::vFind(loggedUsers, name))+1) {
				vector.lock();
				loggedUsers.erase(loggedUsers.begin() + ((int)SideFunctions::vFind(loggedUsers, name)));
				vector.unlock();
			}
			else {
				std::cout << "User doesn't exists!" << std::endl;
			}
			break;
		case CONNNECTED_USERS:
			std::cout << "The connected users are:" << std::endl;
			vector.lock();
			SideFunctions::printVector(loggedUsers);
			vector.unlock();
			break;
		case EXIT:
		default:
			break;
		}
		std::cout << "1.Sign in\n2.Sign out\n3.Connected users\n4.exit\nwhich option would you like: ";
		choise = SideFunctions::inputNum();
		getchar();
		while (choise < SIGNIN || choise > EXIT) {
			std::cout << "1 to 4" << std::endl;
			choise = SideFunctions::inputNum();
			getchar();
		}
	}
}

void MessagesSender::readFile(std::future<void> futureObj) {
	int i = 0;
	std::ifstream myfile;
	std::ofstream clrFile;
	std::string line;
	while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
		myfile.open("data.txt");
		while (i != 59 && futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
			std::this_thread::sleep_for(std::chrono::seconds(1)); // sleeps one sec each time in case the program ends
			i++;
		}
		i = 0;
		// Reads the file
		while (!myfile.eof() && futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
			std::getline(myfile, line);
			queue.lock();
			adminMessages.push(line);
			queue.unlock();
		}
		queueIsEmpty.notify_one();
		// Clear the data from file
		myfile.close();
		if (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
			clrFile.open("data.txt", std::ofstream::trunc);
			clrFile.close();
		}
	}
}

void MessagesSender::sendMessages(std::future<void> futureObj) {
	std::ofstream myfile("output.txt", std::fstream::out);
	std::unique_lock<std::mutex> queueEmpty(queue);
	std::vector<std::string>::iterator it;
	if (myfile.is_open())
	{
		while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
			// Wait until file is not empty and read the file
			queueIsEmpty.wait(queueEmpty);
			if (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
				while (!adminMessages.empty()) {
					vector.lock();
					for (it = loggedUsers.begin(); it != loggedUsers.end(); ++it) { // loop over the users
						myfile << *it << ": " << adminMessages.front() << std::endl;
					}
					vector.unlock();
					adminMessages.pop();
				}
				queue.unlock();
			}
		}
		myfile.close();
	}
	else {
		// Error reading file
		exit(1); // the thread need to stop the process
	}
}