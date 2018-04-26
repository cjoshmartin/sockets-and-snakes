/* timeclnt.c - a client for timeserv.c
 *              usage: timeclnt hostname portnumber
 */
#include <iostream>
#include       <stdio.h>
#include <string.h>
#include  	   <string.h>
#include       <sys/types.h>
#include       <sys/socket.h>
#include       <netinet/in.h>
#include       <netdb.h>
#include 	   <unistd.h>
#include <time.h>
#include "../../include/BoardState.h"

#define        oops(msg)       { perror(msg); exit(1); }
int main(int ac, char *av[])
{
	struct sockaddr_in  servadd;        /* the number to call */
	struct hostent      *hp;            /* used to get number */
	int    sock_id, sock_fd;            /* the socket and fd  */
	//void *   voidPackages;             [> to receive voidPackages <] // TODO: this is giving the bad address voidPackages
	BoardState incoming_state;
	int    messlen;                     /* for voidPackages length */

	int i;
	char clientid[4];

	//make some random ID for this client
	srand (time(NULL));
	sprintf(clientid,"%d", rand()%1000);

	/*
     * Step 1: Get a socket
     */
	sock_id = socket( AF_INET, SOCK_STREAM, 0 );    /* get a line   */
	if ( sock_id == -1 )
	oops( "socket" );          		/* or fail      */

	/*
     * Step 2: connect to server
     *         need to build address (host,port) of server  first
     */

	bzero( &servadd, sizeof( servadd ) );   /* zero the address     */

	hp = gethostbyname( av[1] );            /* lookup host's ip #   */
	if (hp == NULL)
	oops(av[1]);            	/* or die               */
	bcopy(hp->h_addr, (struct sockaddr *)&servadd.sin_addr, hp->h_length);

	servadd.sin_port = htons(atoi(av[2]));  /* fill in port number  */

	servadd.sin_family = AF_INET ;          /* fill in socket type  */

	/* now dial     */
	if ( connect(sock_id,(struct sockaddr *)&servadd, sizeof(servadd)) !=0)
	oops( "connect" );

	/*
     * Step 3: transfer data from server, then hangup
     */

	char buffer[1025];

	// get message from server and check result
	messlen = read(sock_id, buffer, sizeof(int *));     /* read stuff   */
	if ( messlen == - 1 )
		oops("read") ;
int jj = 0;
	// Copy buffered message into object
	memcpy(&jj, buffer, messlen);
	std::cout << jj << "\n";
//	std::cout << incoming_state.test_string << "\n";
//	strncpy(incoming_state.test_string, "hello from the client", 1024);
//	printf("Boardstate size: %d\nMesslen == %d\n", sizeof(BoardState), messlen);
//	printf("%s\n", incoming_state.test_string);
//
	// Copy modified state into buffer
//	memcpy(buffer, &incoming_state,messlen);

	// Send modified state to server and error-check
//	if ( send( sock_id, buffer, messlen,0) != messlen )  /* and write to */
//		oops( "write" );                        /* stdout       */

//	incoming_state.test_string = "Welcome from the client";
//	if ( write( sock_id, (void *)&incoming_state, messlen ) != messlen )  /* and write to */
//	       oops( "write" );                        /* stdout       */

//	while (true) {
////		printf("client %s-%d writing to the server\n",clientid, i);
//		//sprintf(voidPackages, "Greetings from client %s (%i)", clientid, i);
////		messlen = strlen(voidPackages);
////		if ( write( sock_id, voidPackages, messlen ) != messlen )  /* and write to */
////			oops( "write" );
//		//usleep(333*1000);
//
////		messlen = read(sock_id, (void *)(&incoming_state), sizeof(BoardState));     /* read stuff   */
////		if ( messlen == - 1 )
////		oops("read") ;
////		std::cout << incoming_state.test_string << "\n";
//////	incoming_state.test_string = "Welcome from the client";
////		if ( write( sock_id, (void *)&incoming_state, messlen ) != messlen )  /* and write to */
////		oops( "write" );                        /* stdout       */
//
//		sleep(1);
//	}

	close( sock_id );
	return 0;
}
