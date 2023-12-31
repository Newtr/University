
#include "stdafx.h"
#include <string>
#include <iostream>
#include "Winsock2.h" //заголовок WS2_32.dll
#pragma comment(lib, "WS2_32.lib") //экспорт WS2_32.dll
#include "Error.h"
#include <ctime>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	WSADATA wsaData;

	SOCKET cC;

	SOCKADDR_IN serv; 
	serv.sin_family = AF_INET; 
	serv.sin_port = htons(2000); 
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");

	int lobuf = 0;

	clock_t start, stop;
	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		{
			throw SetErrorMsgText("Startup: ", WSAGetLastError());
		}
		while (true)
		{

			if ((cC = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			{
				throw SetErrorMsgText("socket: ", WSAGetLastError());
			}
			int count;
			cout << "Number of messages: ";
			cin >> count;
			start = clock();
			for (int i = 1; i <= count; i++)
			{
					
					string obuf = "Hello from Client " + to_string(i);
					if ((lobuf = sendto(cC, obuf.c_str(), strlen(obuf.c_str()) + 1, NULL, (sockaddr*)&serv, sizeof(serv))) == SOCKET_ERROR)
					{
						throw SetErrorMsgText("sendto: ", WSAGetLastError());
					}
					
					cout << obuf << endl;
			}
			string obuf = "";

			Sleep(1000);
			if ((lobuf = sendto(cC, obuf.c_str(), strlen(obuf.c_str()) + 1, NULL, (sockaddr*)&serv, sizeof(serv))) == SOCKET_ERROR)
			{
				throw SetErrorMsgText("sendto: ", WSAGetLastError());
			}
			stop = clock();
			cout << "Time for sendto and recvfrom: " << (double)((stop - start) / CLK_TCK) << endl;

		}
		if (closesocket(cC) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("closesocket: ", WSAGetLastError());
		}
		if (WSACleanup() == SOCKET_ERROR)
		{
			throw SetErrorMsgText("Cleanup: ", WSAGetLastError());
		}
	}
	catch (string errorMsgText)
	{
		cout << endl << errorMsgText << endl;
	}
	system("pause");
	return 0;
}