#ifndef SERVER_H 
#define SERVER_H

#include "../include/BoardState.h"

void sendToClient(BoardState buffer, int valread, int sd);

void
looper(int master_socket, int max_clients, int client_socket[2], sockaddr_in address, int addrlen, void *startState);
#endif
