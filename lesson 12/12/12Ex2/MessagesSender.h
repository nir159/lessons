#include "SideFunctios.h"

#define SIGNIN 1
#define SIGNOUT 2
#define CONNNECTED_USERS 3
#define EXIT 4

class MessagesSender {
	std::vector<std::string> loggedUsers;
	std::queue<std::string> adminMessages;
	std::condition_variable queueIsEmpty;
	std::mutex vector;
	std::mutex queue;
public:
	//ctor, dtor
	MessagesSender();
	~MessagesSender();
	//menu
	void showMenu();
	void readFile(std::future<void> futureObj);
	void sendMessages(std::future<void> futureObj);
};