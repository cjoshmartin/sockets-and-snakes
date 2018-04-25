#ifndef SERVER_H 
#define SERVER_H

#include "../include/BoardState.h"

void sendToClient(void * buffer,int valread,int sd);

void looper(int master_socket, int max_clients, int client_socket[30], sockaddr_in address, int addrlen,
            BoardState startState, bool *pBoolean);
#endif
