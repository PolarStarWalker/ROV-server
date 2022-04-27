#include "Socket.hpp"

int Socket::MakeServerSocket(uint16_t port) {

    this->status = 1;

    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    this->server_address.sin_family = AF_INET;
    this->server_address.sin_port = htons(port);
    inet_pton(AF_INET, INTERNAL_SERVER_IP, &(this->server_address.sin_addr));

    if (bind(this->server_socket, (sockaddr*)&(this->server_address), this->server_address_lenth) == -1) {
        return(-1);
    }

    return(1);
}

int Socket::Listen() {
    cout << "Server is listening\n";
    if (listen(this->server_socket, SOMAXCONN) == -1) {
        return(-1);
    }

    this->client_socket = accept(this->server_socket, (sockaddr*)&(this->client_address), &(this->client_address_lenth));

    this->ConnectionStatus = true;

    return(1);
}

int Socket::MakeConnection(int port) {

    this->status = 0;
    
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);

    this->server_address.sin_family = AF_INET;
    this->server_address.sin_port = htons(port);
    inet_pton(AF_INET, EXTERNAL_SERVER_IP, &(this->server_address.sin_addr));
    this->server_address_lenth = sizeof(this->server_address);

    if (connect(this->server_socket, (sockaddr*)&(this->server_address), (this->server_address_lenth)) == -1) {
        return(-1);
    }

    this->ConnectionStatus = true;

    return(1);
}

int Socket::RecvData(char *msg) {
        if (this->status == SERVER) {
            this->recvall(this->client_socket, msg, MSG_SIZE, 0);
        }
        else if (Socket::status == CLIENT) {
            this->recvall(this->server_socket, msg, MSG_SIZE, 0);
        }
        else {
            return(-1);
        }
        return(1);
}

int Socket::SendData(char *msg) {

    if (this->status == SERVER) {
        this->sendall(this->client_socket, msg, MSG_SIZE, 0);
    }
    else if (Socket::status == CLIENT) {
        this->sendall(this->server_socket, msg, MSG_SIZE, 0);
    }
    else {
        return(-1);
    }
    return(1);
}

int Socket::RecvDataLen(char *msg, size_t len){
    int Rezalt = 0;
    if (this->status == SERVER) {
        Rezalt = this->recvall(this->client_socket, msg, len, 0);
    }
    else if (Socket::status == CLIENT) {
        Rezalt = this->recvall(this->server_socket, msg, len, 0);
    }
    else {
        return(-1);
    }
    return(Rezalt);
}

int Socket::SendDataLen(char *msg, size_t len){
    int Rezalt = 0;
    if (this->status == SERVER) {
        Rezalt = this->sendall(this->client_socket, msg, len, 0);
    }
    else if (Socket::status == CLIENT) {
        Rezalt = this->sendall(this->server_socket, msg, len, 0);
    }
    else {
        return(-1);
    }
    return(Rezalt);
}

int Socket::recvall(int s, char* buf, int len, int flags) {
    int total = 0;
    int n;
    while (total < len) {
        n = recv(s, buf + total, len - total, flags);
        if (n == -1) { break; }
        total += n;
    }

    if(n==-1){
        this->ConnectionStatus = false;
        return -1;
    }else{
        return total;
    }
}

int Socket::sendall(int s, char* buf, int len, int flags) {
    int total = 0;
    int n;
    while (total < len) {
        n = send(s, buf + total, len - total, flags);
        if (n == -1) { break; }
        total += n;
    }

    if(n==-1){
        this->ConnectionStatus = false;
        return -1;
    }else{
        return total;
    }

}

bool Socket::GetSocketConnectionStatus() {
    return this->ConnectionStatus;
}

int& Socket::ReturnDescriptor() {
    return this->server_socket;
}


Socket::~Socket(){
    if(this->server_socket!=-1){close(this->server_socket);}
}
