#include <WinSock2.h>

#include <iostream>

bool setUpConnectionIPv4(const char* IP, int PORT) {
	SOCKET client_IPv4 = socket(AF_INET, SOCK_STREAM, 0);
	if (client_IPv4 == INVALID_SOCKET) {
		std::cout << "Socket connection error for IPv4";
		return false;
	}
	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT); 
	serverAddress.sin_addr.s_addr = inet_addr(IP);
	
	if(connect(client_IPv4, (struct sockaddr*)&serverAddress, sizeof(serverAddress))==SOCKET_ERROR) {
		std::cout << "Fail to connect";
		closesocket(client_IPv4);
		return false;
	}

	return true;
}

int main() {
	
}

//Some note:

/*
*calling WSADATA to store information about the winsock implementations:

	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cerr << "Failed to initialize WinSock." << std::endl;
		return false;
	}

	remember to release data by WSACleanup();

*/

/*
#include <arpa/inet.h>

 if (inet_pton(AF_INET, "127.168.0.1", &serv_addr.sin_addr) <= 0) {
		std::cout << "Invalid address");
		return ;
	}

	checking ips
*/

/*
* sent message example :

	const char* greetingFromClient ="Hello I'm client! ";
	int SentBytes = send(client_IPv4, greetingFromClient, strlen(greetingFromClient), 0);

	if (SentBytes == SOCKET_ERROR) {
		int errorCode = WSAGetLastError();
		std::cout << "Fail to sent message";
	}
	else {
		std::cout << "Success";
	}

*/

/*
* receive message example :

	char receiveMessage[1024];
	int ReceviveBytes = recv(client_IPv4, receiveMessage, sizeof(receiveMessage), 0);

	if (ReceviveBytes > 0) {
		std::cout << receiveMessage << std::endl;
	}
	else if (ReceviveBytes == 0) {
		std::cout << "Connection close";
	}
	else {
		std::cout << "Fail to receive";
	}

*/