/* The objective of this program is to fetch the IP address of a hostname  */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Note -

// This is an ipv4 address: 192.0.2.111. (32 bits or 4 bytes)
// In IPv4, the loopback address is 127.0.0.1.

// 1 byte can store from 0 to 255. - four numbers each from 0 to 255.


//this is an ipv6 address: 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551

//You can compress the zeros, For instance, each of these pairs of addresses are equivalent:

//     2001:0db8:c9d2:0012:0000:0000:0000:0051 (128 bits)
//     2001:db8:c9d2:12::51

// In IpV6, the loopback address is ::1.


int main(int argc,char *argv[]){

    // This is the struct
    // struct addrinfo
    //     {
    //     int ai_flags;			/* Input flags.  */
    //     int ai_family;		/* Protocol family for socket. -ipv4 or ipv6 */
    //     int ai_socktype;		/* Socket type.  */
    //     int ai_protocol;		/* Protocol for socket.  */
    //     socklen_t ai_addrlen;		/* Length of socket address.  */
    //     struct sockaddr *ai_addr;	/* Socket address for socket.  */
    //     char *ai_canonname;		/* Canonical name for service location.  */
    //     struct addrinfo *ai_next;	/* Pointer to next in list.  */
    //     };


	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];


	/* Check for exactly two argument count i.e argv[0] is the name of our program and argv[1] should be the hostname*/

	if(argc !=2) {
		fprintf(stderr,"usage:fetchip hostname");
		return 1;
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC; //either ipv4 or ipv6
	hints.ai_socktype = SOCK_STREAM; //stream(TCP) or datagram (UDP)

    // int getaddrinfo(const char *node,     // e.g. "www.example.com" or IP
    //                 const char *service,  // e.g. "http" or port number
    //                 const struct addrinfo *hints, //fill this struct with info before
    //                 struct addrinfo **res); //return pointer to a LL


	if(status = getaddrinfo(argv[1], NULL, &hints, &res) != 0 ){
		fprintf (stderr, "getaddrinfo: %s\n", gai_strerror(status));
        fprintf (stderr, "status: %d\n", status);
		return 2;
	}

	printf("IP addresses for %s:\n\n", argv[1]);

    // struct sockaddr {
    //     unsigned short    sa_family;    // address family, AF_xxx - AF_INET, AF_INET6 for ipv4 and ipv6 respectively
    //     char              sa_data[14];  // 14 bytes of protocol address
    // }; 

	// sockaddr holds socket address information - you don't use this directly, instead you use sockaddr_in or sockaddr_in6.

	//     struct sockaddr_in {
    //     short int          sin_family;  // Address family, AF_INET
    //     unsigned short int sin_port;    // Port number
    //     struct in_addr     sin_addr;    // Internet address - a 32-bit IPv4 address
    //     unsigned char      sin_zero[8]; // Same size as struct sockaddr
    // };

	for (p = res; p!= NULL; p =p->ai_next)  {
		void *addr;
		char *ipver;
		if (p->ai_family == AF_INET) { //if AF_INET then assume ipv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr; 
			addr = &(ipv4->sin_addr);
			ipver = "IPV4";
		}else{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}

		// struct sockaddr_in sa; // IPv4
		// struct sockaddr_in6 sa6; // IPv6
		

		//These functions convert an IPv4 or IPv6 address from numbers-and-dots notation into a struct in_addr or struct in6_addr structure.
		// inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr)); // IPv4
		// inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6


		//ntop does the opposite thing...
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr); 
		printf("  %s: %s\n", ipver, ipstr);
	}
	freeaddrinfo(res); // free the linked list
	return 0;
}