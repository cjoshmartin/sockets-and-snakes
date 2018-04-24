/* timeserv.c - a socket-based time of day server
 */

#include  <stdio.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/socket.h>
#include  <netinet/in.h>
#include  <netdb.h>
#include  <time.h>
#include  <strings.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

//#define   PORTNUM  3146   /* our time service phone number */
#define   HOSTLEN  256
#define   oops(msg)      { perror(msg) ; exit(1) ; }

int main(int ac, char *av[])
{
	struct  sockaddr_in   saddr;   /* build our address here */
	struct	hostent		*hp;   /* this is part of our    */
	char	hostname[HOSTLEN];     /* address 	         */
	int	sock_id,sock_fd;       /* line id, file desc     */
	FILE	*sock_fp;              /* use socket as stream   */
	char    *ctime();              /* convert secs to string */
	time_t  thetime;               /* the time we report     */
	char msg[256];
	int msglen;

	int portnum;
	
	if (ac < 2) {
		printf("Error with args.\n");
		exit(0);
	}
	portnum = atoi(av[1]);
	if (portnum <= 0)
		oops("portnum arg");

      /*
       * Step 1: ask kernel for a socket
       */
	printf("%d\n", portnum);

	sock_id = socket( PF_INET, SOCK_STREAM, 0 );    /* get a socket */
	if ( sock_id == -1 ) 
		oops( "socket" );

      /*
       * Step 2: bind address to socket.  Address is host,port
       */

	bzero( (void *)&saddr, sizeof(saddr) ); /* clear out struct     */

	gethostname( hostname, HOSTLEN );       /* where am I ?         */
	hp = gethostbyname( hostname );         /* get info about host  */
	                                        /* fill in host part    */
	bcopy( (void *)hp->h_addr, (void *)&saddr.sin_addr, hp->h_length);
	saddr.sin_port = htons(portnum);        /* fill in socket port  */
	saddr.sin_family = AF_INET ;            /* fill in addr family  */

	if ( bind(sock_id, (struct sockaddr *)&saddr, sizeof(saddr)) != 0 )
	       oops( "bind" );

      /*
       * Step 3: allow incoming calls with Qsize=1 on socket
       */

	if ( listen(sock_id, 1) != 0 ) 
		oops( "listen" );

      /*
       * main loop: accept(), write(), close()
       */

	while ( 1 ){
	       sock_fd = accept(sock_id, NULL, NULL); /* wait for call */
		printf("Wow! got a call!\n");
	       if ( sock_fd == -1 )
		       oops( "accept" );       /* error getting calls  */

	       sock_fp = fdopen(sock_fd,"r+");  /* we'll write to the   */
	       if ( sock_fp == NULL )          /* socket as a stream   */
		       oops( "fdopen" );       /* unless we can't      */

		   // Read from the socket (client's message)
		   //fscanf(sock_fp, msg, 256);
		   msglen = read(sock_fd, msg, 256);
		   printf("Server: original msg: %s\n", msg);
		   msg[strlen(msg)-1] = '!';
		   fprintf(sock_fp, "%s\n", msg);

	       //thetime = time(NULL);           /* get time             */
					       /* and convert to strng */
	       //fprintf( sock_fp, "The time here is .." );
	       //fprintf( sock_fp, "%s", ctime(&thetime) ); 
		   
	       fclose( sock_fp );              /* release connection   */
	}
}
