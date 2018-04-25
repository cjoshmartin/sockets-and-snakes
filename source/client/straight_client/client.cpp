/* timeclnt.c - a client for timeserv.c
 *              usage: timeclnt hostname portnumber
 */
#include <iostream>
#include       <stdio.h>
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

	messlen = read(sock_id, (void *)(&incoming_state), sizeof(BoardState));     /* read stuff   */
	if ( messlen == - 1 )
	oops("read") ;
	std::cout << incoming_state.test_string << "\n";
//	incoming_state.test_string = "Welcome from the client";
//	if ( write( sock_id, (void *)&incoming_state, messlen ) != messlen )  /* and write to */
//	       oops( "write" );                        /* stdout       */

	while (true) {
//		printf("client %s-%d writing to the server\n",clientid, i);
		//sprintf(voidPackages, "Greetings from client %s (%i)", clientid, i);
//		messlen = strlen(voidPackages);
//		if ( write( sock_id, voidPackages, messlen ) != messlen )  /* and write to */
//			oops( "write" );
		//usleep(333*1000);

		messlen = read(sock_id, (void *)(&incoming_state), sizeof(BoardState));     /* read stuff   */
		if ( messlen == - 1 )
		oops("read") ;
		std::cout << incoming_state.test_string << "\n";
//	incoming_state.test_string = "Welcome from the client";
		if ( write( sock_id, (void *)&incoming_state, messlen ) != messlen )  /* and write to */
		oops( "write" );                        /* stdout       */

		sleep(1);
	}

	close( sock_id );
	return 0;
}
