#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//ip settings
#define EXTERNAL_SERVER_IP "192.168.0.50" //Server ip for other computers
#define INTERNAL_SERVER_IP "0.0.0.0" //Server ip for server
//Messege size
#define MSG_SIZE 40 //message size
//client-server settings
#define SERVER 1
#define CLIENT 0

using namespace std;

class Socket {
public:

	//Functions for making server socket
	int MakeServerSocket(uint16_t port);
	int Listen();

	//Function for making client socket
	int MakeConnection(int port);

	//Functions for data transfer 
	int RecvData(char *msg);
	int SendData(char *msg);

	//Return descriptor for closing Socket
	int& ReturnDescriptor();

	~Socket();

	int RecvDataLen(char *msg, size_t len);
	int SendDataLen(char * msg, size_t len);

	bool GetSocketConnectionStatus();

protected:

	//status (server or client)
	int status;

	bool ConnectionStatus = false;

	//socket descriptors
	int server_socket;
	int client_socket;

	//connection data
	sockaddr_in server_address;
	sockaddr_in client_address;

	//I don't know what is it, but it needs, chestno
	socklen_t server_address_lenth = sizeof(this->server_address);
	socklen_t client_address_lenth = sizeof(this->client_address);

	//Simple functions, for transfer data
	inline int recvall(int s, char* buf, int len, int flags);
	inline int sendall(int s, char* buf, int len, int flags);
};

