#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
    
// int socket(int domain, int type, int protocol); 

    

/* Create a new socket of type TYPE in domain DOMAIN, using
   protocol PROTOCOL.  If PROTOCOL is zero, one is chosen automatically.
   Returns a file descriptor for the new socket, or -1 for errors.  */

// extern int socket (int __domain, int __type, int __protocol) __THROW;

// domain is PF_INET or PF_INET6, type is SOCK_STREAM or SOCK_DGRAM, 
// and protocol can be set to 0 to choose the proper protocol for the given type. 
// Or you can call getprotobyname() to look up the protocol you want, “tcp” or “udp”.)


//Bind======
//   int bind(int sockfd, struct sockaddr *my_addr, int addrlen);  //bind the socket to a port - you need to do this before you can listen on a port 

// if you're the client, you only need to do a connect, bind is on the server side 

int main() {
    struct addrinfo hints;
    struct addrinfo *res; 

    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;   
    hints.ai_socktype = SOCK_STREAM; 

    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    // By using the AI_PASSIVE flag, I’m telling the program to bind to the IP of the host it’s running on.
    // If you want to bind to a specific local IP address, 
    // drop the AI_PASSIVE and put an IP address in for the first argument to getaddrinfo().


//if you want the socket for google.com, you can use the following code:
    // int status = getaddrinfo("www.google.com", "80", &hints, &res); //name, port, addrinfo struct with info, result pointer
    // if (status != 0) {
	// 	fprintf (stderr, "getaddrinfo: %s\n", gai_strerror(status));
    // }

    int status = getaddrinfo(NULL, "3490", &hints, &res); //name, port, addrinfo struct with info, result pointer = bind to port 3490 of your own machine
    if (status != 0) {
		fprintf (stderr, "getaddrinfo: %s\n", gai_strerror(status));
    }



    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    fprintf(stderr, "\n socket: %d \n", s); //socket =3, -1 on error

    int b = bind(s, res->ai_addr, res->ai_addrlen); //bind to port 3490 of your own machine
    fprintf(stderr, "\n bind: %d \n", b); //bind = 0, -1 on error

    freeaddrinfo(res);
}