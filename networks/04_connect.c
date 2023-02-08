#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
    
//     int connect(int sockfd, struct sockaddr *serv_addr, int addrlen); 


// difference between connect and bind?

// In one sentence: bind is to local address, connect is to remote address

// The connect() system call connects a socket, identified by its file descriptor, 
// to a remote host specified by that host's address in the argument list.

// bind() assigns a socket to an address. 
// When a socket is created using socket(), it is only given a protocol family, but not assigned an address. 

int main() {
    struct addrinfo hints;
    struct addrinfo *res; 

    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;   
    hints.ai_socktype = SOCK_STREAM; 

    int status = getaddrinfo("www.example.com", "3490", &hints, &res); //name, port, addrinfo struct with info, result pointer = bind to port 3490 of your own machine
    if (status != 0) {
		fprintf (stderr, "getaddrinfo: %s\n", gai_strerror(status));
    }

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    fprintf(stderr, "\n socket: %d \n", s); //socket =3, -1 on error

    int c = connect(s, res->ai_addr, res->ai_addrlen);
    fprintf(stderr, "\n connect: %d \n", c); //connect = 0, -1 on error

    freeaddrinfo(res);
}