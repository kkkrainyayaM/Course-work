#include "Connection.h"

Connection *Connection::instance = 0;

int Connection::sendUserReg(User user) {
	string log = user.getLogin(),
		pas = user.getPassword(),
		name = user.getName();
	char *log1 = log.c_str,
		*pas1 = pas.c_str,
		*name1 = name.c_str,
		*id1;
	itoa(user.getID(), id1, 10);
	iResult = send(ConnectSocket, log1, (int)strlen(log1), 0);
	iResult = send(ConnectSocket, pas1, (int)strlen(pas1), 0);
	iResult = send(ConnectSocket, name1, (int)strlen(name1), 0);
	iResult = send(ConnectSocket, id1, (int)strlen(id1), 0);
}

Connection* Connection::getInstanse(int argc, char **argv) {
	if (!instance) {
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
		SOCKET ConnectSocket = INVALID_SOCKET;
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			freeaddrinfo(result);
		}
		return instance;
	}
}

void Connection::sendUser(User user) {
	string log = user.getLogin(),
		pas = user.getPassword();
	char *log1 = log.c_str,
		*pas1 = pas.c_str;
	iResult = send(ConnectSocket, log1, (int)strlen(log1), 0);
	iResult = send(ConnectSocket, pas1, (int)strlen(pas1), 0);
	iResult = shutdown(ConnectSocket, SD_SEND);
}

void Connection::sendAdmin(Admin admin) {
	string log = admin.getLogin(),
		pas = admin.getPassword();
	char *log1 = log.c_str,
		*pas1 = pas.c_str;
	iResult = send(ConnectSocket, log1, (int)strlen(log1), 0);
	iResult = send(ConnectSocket, pas1, (int)strlen(pas1), 0);
	iResult = shutdown(ConnectSocket, SD_SEND);
}

void Connection::getUser(User user) {
	char *log1, *pas1, *name1;
	iResult = recv(ConnectSocket, log1, recvbuflen, 0);
	iResult = recv(ConnectSocket, pas1, recvbuflen, 0);
	iResult = recv(ConnectSocket, name1, recvbuflen, 0);
	string log, pas, name;
	log = (char *)log1;
	pas = (char *)pas1;
	name = (char *)name1;
	user.setLog(log);
	user.setPas(pas);
	user.setName(name);
}

void Connection::getAdmin(Admin admin) {
	char *log1, *pas1, *name1;
	iResult = recv(ConnectSocket, log1, recvbuflen, 0);
	iResult = recv(ConnectSocket, pas1, recvbuflen, 0);
	iResult = recv(ConnectSocket, name1, recvbuflen, 0);
	string log, pas, name;
	log = (char *)log1;
	pas = (char *)pas1;
	name = (char *)name1;
	user.setLog(log);
	user.setPas(pas);
	user.setName(name);
}