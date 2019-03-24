#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (struct sockaddr*) &peer, sizeof(peer));
	char buf[50], res[50];
	cout << "Соединение с сервером... Соединение установлено!" << endl << endl;
	/*cout << "Введите числа через пробел: ";
	cin.getline(buf, 50);
	send(s, buf, sizeof(buf), 0);
	if (recv(s, res, sizeof(res), 0) != 0) {
		res[strlen(res)] = '\0';
		cout << "Количество чисел, кратных 3: " << res << endl;
	}*/
	closesocket(s);
	cout << "\n" << endl;
	system("pause");
	WSACleanup();
	return 0;
}