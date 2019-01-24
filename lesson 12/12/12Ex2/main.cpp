#include "MessagesSender.h"

int main() {
	MessagesSender msgObj;
	std::promise<void> exitSignal;
	std::future<void> futureObj = exitSignal.get_future(); // catch the thread using promise
	std::promise<void> exitSignalSecond;
	std::future<void> futureObjSecond = exitSignalSecond.get_future();
	std::thread input(&MessagesSender::readFile, &msgObj, std::move(futureObj));
	std::thread output(&MessagesSender::sendMessages, &msgObj, std::move(futureObjSecond));
	msgObj.showMenu();
	// Set the value in promise to end threads
	exitSignal.set_value();
	exitSignalSecond.set_value();
	//Wait for thread to join
	input.join();
	output.join();
	system("PAUSE");
	return 0;
}