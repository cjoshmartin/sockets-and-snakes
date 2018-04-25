//Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux 
#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h>   //close 
#include <arpa/inet.h>    //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 

#include <signal.h>

#include "server.h"

#define TRUE   1
#define FALSE  0
#define PORT 9888// 1025 - 32000


int main(int argc , char *argv[])  
{  
    int opt = TRUE;  

    int master_socket ,
        addrlen ,
        client_socket[30] , 
        max_clients = 30 ,
        i;  

    struct sockaddr_in address;  

    // ** IMPORTANT ** for simplicity, ignore SIGPIPE
    signal(SIGPIPE, SIG_IGN);
    // When you call send() on an already closed connection, the
    // operating system may issue SIGPIPE to your process. Usually
    // the default handler for SIGPIPE is to kill your process.
    // In order to prevent this from occurring, you can either ignore
    //	the signal (e.g., with signal(SIGPIPE, SIG_IGN) or
    //	sigignore(SIGPIPE)), or you can pass the MSG_NOSIGNAL option to send():
    /*
       int send_result = send(newfd, ok, 3, MSG_NOSIGNAL);
       if (send_result >= 0) {
    // okay, but check if all your data got sent! 
    if (send_result < 3){} // ...do something
    } else {
    switch (errno) {
    // some other cases
    case EPIPE:
    // sending on a closed connection...
    }
    }
    */

    //initialise all client_socket[] to 0 so not checked 
    for (i = 0; i < max_clients; i++)  
    {  
        client_socket[i] = 0;  
    }  

    //create a master socket 
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)  
    {  
        perror("socket failed");  
        exit(EXIT_FAILURE);  
    }  

    //set master socket to allow multiple connections , 
    //this is just a good habit, it will work without this 
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, 
                sizeof(opt)) < 0 )  
    {  
        perror("setsockopt");  
        exit(EXIT_FAILURE);  
    }  

    //type of socket created 
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons( PORT );  

    //bind the socket to localhost port 8888 
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)  
    {  
        perror("bind failed");  
        exit(EXIT_FAILURE);  
    }  
    printf("Listener on port %d \n", PORT);  

    //try to specify maximum of 3 pending connections for the master socket 
    if (listen(master_socket, 3) < 0)  
    {  
        perror("listen");  
        exit(EXIT_FAILURE);  
    }  

    //accept the incoming connection 
    addrlen = sizeof(address);  
    puts("Waiting for connections ...");  

    BoardState startState; // board state
    bool isSetup = true;

    //set of socket descriptors 
    while(TRUE)  
    {
        looper(master_socket, max_clients, client_socket, address, addrlen, startState, &isSetup);
    } // end of while(TRUE) 

    return 0;  
} // end of main



