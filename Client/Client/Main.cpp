#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"

//#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")
//
//#define DEFAULT_BUFLEN 512
//#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char **argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL, 
		hints;
	char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;*/

	// Validate the parameters
	/*if (argc != 2) {
		printf("usage: %s server-name\n", argv[0]);               //why argc=1??
		return 1;
	}*/

	/*iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);*/
	/*if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}*/

	/*ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}*/

	//for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

	//	// Create a SOCKET for connecting to server
	//	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
	//		ptr->ai_protocol);
	/*	if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}*/

		// Connect to server.
	/*	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}*/

	/*freeaddrinfo(result);*/

	//if (ConnectSocket == INVALID_SOCKET) {
	//	printf("Unable to connect to server!\n");
	//	WSACleanup();
	//	return 1;
	//}

	//// Send an initial buffer
	//iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	//if (iResult == SOCKET_ERROR) {
	//	printf("send failed with error: %d\n", WSAGetLastError());
	//	closesocket(ConnectSocket);
	//	WSACleanup();
	//	return 1;
	//}


	// shutdown the connection since no more data will be sent
	/*iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}*/

		char menu1 = NULL;
		int vozvr;
		while (menu1 != 27) {
			system("cls");
			cout << setw(66) << "ДОБРО ПОЖАЛОВАТЬ!" << endl << endl;
			cout << setw(67) << "Выберите пункт меню:" << endl
				<< setw(65) << "1.Регистрация пользователя" << endl
				<< setw(58) << "2.Вход в учетную запись" << endl
				<< setw(59) << "ESC.Выход" << endl << endl
				<< setw(61) << "Ваш выбор: ";
			menu1 = _getche();
			switch (menu1) {
			case '1':
				system("cls");
				vozvr = (Menu::registration());
				switch (vozvr) {
				case 1:
					Menu::menuUser();//переделать
					system("pause");
					break;
				default:
					cout << "\nПроизошла Ошибка!" << endl;
					system("pause");
					break;
				}
				break;

			case '2':
			{
				system("cls");
				Role role;
				role = Menu::autorization();
				switch (role) {
				case ADMIN:
					Menu::menuAdmin();
					system("pause");
					break;
				case USER:
					Menu::menuUser();
					system("pause");
					break;
				default:
					cout << "\nПроизошла Ошибка!" << endl;
					system("pause");
					break;
				}
				break;

			}
			case 27:
				cout << " Всего Доброго!" << endl;
				break;
			default:
				cout << "\nВыберите пункт меню корректно" << endl;
				system("pause");
				break;
			}
		}
		/*iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed with error: %d\n", WSAGetLastError());

	} while (iResult > 0);*/

	// cleanup
	/*closesocket(ConnectSocket);
	WSACleanup();*/
	system("pause");
	return 0;
}