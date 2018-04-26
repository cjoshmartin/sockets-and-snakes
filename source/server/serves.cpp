#include <stdio.h>
#include <stdlib.h> 
#include <errno.h> 
#include <sys/select.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "server.h"
#include "../include/SnakeFood.h"
#include "../include/SnakeHead.h"

void looper(int master_socket, int max_clients, int client_socket[2], sockaddr_in address, int addrlen, void *startState)
{
    fd_set readfds;

    int max_sd,
        activity,
        valread,
        sd,
        new_socket,
        i;

    char buffer[1025];
    //a message 
    char *message = "Welcome! We are waiting for another player  to show up\r\n";

    //clear the socket set 
    FD_ZERO(&readfds);  

    //add master socket to set 
    FD_SET(master_socket, &readfds);  
    max_sd = master_socket;  

    //add child sockets to set 
    for ( i = 0 ; i < max_clients ; i++)  
    {  
        //socket descriptor 
        sd = client_socket[i];  

        //if valid socket descriptor then add to read list 
        if(sd > 0)  
            FD_SET( sd , &readfds);  

        //highest file descriptor number, need it for the select function 
        if(sd > max_sd)  
            max_sd = sd;  
    }  

    //wait for an activity on one of the sockets , timeout is NULL , 
    //so wait indefinitely 
    activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);  

    if ((activity < 0) && (errno!=EINTR))  
    {  
        printf("select error");  
    }  

    //If something happened on the master socket , 
    //then its an incoming connection 
    if (FD_ISSET(master_socket, &readfds))  
    {  
        if ((new_socket = accept(master_socket, 
                        (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)  
        {  
            perror("accept");  
            exit(EXIT_FAILURE);  
        }  

        //inform user of socket number - used in send and receive commands 
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n" ,
                new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));  

        //send new connection greeting message
        //memcpy(buffer,&startState, sizeof(BoardState));
		int hello = 42;
        if( send(new_socket, &hello, sizeof(int), 0) != sizeof(startState))
        {  
            perror("send");  
        }  

        puts("Welcome message sent successfully");  

        //add new socket to array of sockets 
        for (i = 0; i < max_clients; i++)  
        {  
            //if position is empty 
            if( client_socket[i] == 0 )   // <--TODO:check if client has never connected before
            {
                client_socket[i] = new_socket;
                char *message = "HELLO, TEST ECHO\n";

                break;
            }  
        }  
    }  

    //else its some IO operation on some other socket
    for (i = 0; i < max_clients; i++)
    {
        sd = client_socket[i];

        if (FD_ISSET( sd , &readfds))
        {

            //Check if it was for closing , and also read the
            //incoming message
            if ((valread = read( sd ,buffer, sizeof(BoardState))) == 0)
            {
                //Somebody disconnected , get his details and print
                getpeername(sd , (struct sockaddr*)&address , \
                        (socklen_t*)&addrlen);
                printf("Client disconnected , ip %s , port %d \n" ,
                        inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

                //Close the socket and mark as 0 in list for reuse
                close( sd );
                client_socket[i] = 0;
            }


            //Echo back the message that came in
            else
            {
				BoardState state;
				state.game_on = false;
				printf("Sending to client\n");
				if (send(sd, &state, sizeof(BoardState), 0) != sizeof(BoardState)) {
					perror("BoardState send");
					exit(1);
				}
				printf("bye bye\n");
            }// end of else statement

        }// end of outer if statement
    } // end of for loop, looping over max_clients

} //end of looper


void sendToClient(BoardState state, int valread, int sd)
{
//    std::cout << state.test_string << "\n";
    //set the string terminating NULL byte on the end
    //of the data read 
    //printf("Read from the client: %s\n", buffer);
//    send(sd , (void *)&state , sizeof(BoardState), 0 );  // NOTE: sends data back,
                                                //one client at a time 
}

