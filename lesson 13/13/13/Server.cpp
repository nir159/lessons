#include "Server.h"

Server::Server()
{

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET,  SOCK_STREAM,  IPPROTO_TCP); 

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Server::~Server()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Server::serve(int port)
{
	
	struct sockaddr_in sa = { 0 };
	
	sa.sin_port = htons(port); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// again stepping out to the global namespace
	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	
	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << port << std::endl;

	while (true)
	{
		// the main thread is only accepting clients 
		// and creates thread for each one
		std::cout << "Waiting for client connection request" << std::endl;
		accept();
	}
}


void Server::accept()
{
	// notice that we step out to the global namespace
	// for the resolution of the function accept

	// this accepts the client and create a specific socket from server to this client
	// then creates new thread and add it to the threads queue - users
	SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);

	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::cout << "Client accepted. Server and client can speak" << std::endl;

	// the function that handle the conversation with the client
	std::thread newUser(&Server::clientHandler, this, client_socket);
	newUser.detach();
}


void Server::clientHandler(SOCKET clientSocket)
{
	try
	{
		// gets the username and adds to the users vector
		std::string msg = Helper::getStringPartFromSocket(clientSocket, MAX_BYTES); // gets the message
		int lengthName = std::atoi(msg.substr(3, 2).c_str()); // the length of the name
		std::string name = msg.substr(5, lengthName);
		users.push_back(name);

		// send the info to the user
		Helper::sendUpdateMessageToClient(clientSocket, Helper::readFile(FILE), name, Helper::getNextUser(users, name), Helper::vFind(users, name));





		std::this_thread::sleep_for(std::chrono::seconds(3615));
		/*send(clientSocket, s.c_str(), s.size(), 0);  // last parameter: flag. for us will be 0.
		recv(clientSocket, m, 4, 0);
		if (std::this_thread::get_id() == users.front().get_id()) {
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}*/
		/*
		200:
			
			// moving the thread to the end of queue
			changeUser.lock();
			users.push(users.front());
			users.pop();
			changeUser.unlock();
		208:
			users.pop();
			closesocket(clientSocket);

		*/
		

	}
	catch (const std::exception& e)
	{
		closesocket(clientSocket);
	}


}

