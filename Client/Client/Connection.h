#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "User.h"
#include "Admin.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

class Connection {
private:
	static WSADATA wsaData;
	static SOCKET ConnectSocket;
	static struct addrinfo *result /*= NULL*/;
	static struct addrinfo *ptr/* = NULL*/;
	static struct addrinfo hints;
	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	static int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	User user;
	Admin admin;

	static Connection *instance;
	Connection() {}
	~Connection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}

public:
	static Connection* getInstanse(int argc, char **argv);
	int sendUserReg(User user);//при регистрации пользователя
	void sendUser(User user);// при входе
	void sendAdmin(Admin admin);
	void getUser(User user);// при входе
	void getAdmin(Admin admin); 
};
