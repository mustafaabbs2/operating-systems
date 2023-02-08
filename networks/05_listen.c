#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
    

    // What if you don’t want to connect to a remote host????
    // Say, just for kicks, that you want to wait for incoming connections and handle them in some way.
    //  The process is two step: first you listen(), then you accept() (see below).
//     int listen(int sockfd, int backlog); 


#define MYPORT "3490"  // the port users will be connecting to
#define BACKLOG 10     // how many pending connections queue will hold


int main(void)
{
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, new_fd;

    // !! don't forget your error checking for these calls !!

    // first, load up address structs with getaddrinfo():

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

    getaddrinfo(NULL, MYPORT, &hints, &res);

    // make a socket, bind it, and listen on it:

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    listen(sockfd, BACKLOG);

    // now accept an incoming connection:

    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

    // ready to communicate on socket descriptor new_fd!
    // use the socket descriptor new_fd for all send() and recv() calls.

        // int recv(int sockfd, void *buf, int len, int flags);
        //  int send(int sockfd, const void *msg, int len, int flags);  //send to socket descriptor, msg is a pointer to a buffer, len is the length of the buffer, flags is 0 for default


        //if recv returns 0, then the connection has been closed


     
      // for datagram sockets, recvfrom() and sendto() are used instead of recv() and send()
        // int sendto(int sockfd, const void *msg, int len, unsigned int flags,
        //    const struct sockaddr *to, socklen_t tolen); 

            // int sendto(int sockfd, const void *msg, int len, unsigned int flags,
            //    const struct sockaddr *to, socklen_t tolen); 


      close(sockfd);

}