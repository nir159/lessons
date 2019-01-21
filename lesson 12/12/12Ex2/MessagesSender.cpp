#include "MessagesSender.h"

//ctor, dtor
MessagesSender::MessagesSender() { }

MessagesSender::~MessagesSender(){ }

void MessagesSender::showMenu() {
	int choise = 0;
	std::cout << "1.Sign in\n2.Sign out\n3.Connected users\n4.exit\nwhich option would you like: ";
	while (!(std::cin >> choise) || (choise < 1 || choise > 4)) {
		std::cout << "Bad value!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

}

/*std::ofstream myfile("data.txt");
if (myfile.is_open())
{
	myfile << "This is a line.\n";
	myfile << "This is another line.\n";
	myfile.close();
}
else cout << "Unable to open file";*/