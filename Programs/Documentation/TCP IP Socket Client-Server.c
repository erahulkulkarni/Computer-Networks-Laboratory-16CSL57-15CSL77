 /* 
   Computer Networks Laboratory (Lab) 15CSL77
   8. Using TCP/IP sockets, write a client-server program to make client sending 
        the file name and the server to send back the contents of the requested 
        file if present.
 */

 /*Process-to-process delivery needs two identifiers,\
     IP address and the port number, at each end to make a connection

   IP to recognize computer on network, port number to recognize process on 
     the computer

   IP Address: uniquely defines a host on the Internet, logical addressing, 
     hierarchical

   Socket Addresses: combination of an IP address and a port number  

   Sockets can be used for interprocess communication(IPC)

   In UNIX - every thing looks like a file!

   Socket is a type of file used for network communication between processes, 
     network IPC, IPC Inter Process Communication
   Or for non-network communication between processes on a single host

   UNIX domain sockets are full duplex by default   
 */

 /*Mechanisms of processes running on the same computer to communicate with 
     one another: pipes, FIFOs, message queues, semaphores, and shared memory

   Mechanisms that allow processes running on different computers (connected to 
     a common network) to communicate with one another: network IPC

   Socket network IPC interface, can be used by processes to communicate with 
     other processes, regardless of where they are running: on the same machine 
     or on different machines

   Intermachine communication and Intramachine communication

   TCP/IP protocol can be used to communicate
 */

 /*Socket interfaces: originally introduced in BSD in the early 1980s

   socket is an abstraction of a communication endpoint

   Like file descriptors used to access a file, socket descriptors used to access 
     sockets

   Functions that deal with file descriptors, such as read and write , will work 
     with a socket descriptor

   To create a socket, use the socket function

     #include <sys/socket.h>
     int socket(int domain, int type, int protocol);

     Returns: file (socket) descriptor if OK, –1 on error
     
     domain:  nature of the communication, like AF_ (for address family)
       AF_INET IPv4 Internet domain  , or AF_INET6 for IPv6 protocol

     type: type of the socket, communication characteristics, like SOCK_STREAM
       meaning sequenced, reliable, bidirectional, connection-oriented byte streams
    
     protocol: usually zero, selects default protocol for given domain, socket type

     When done using the file descriptor, call close to relinquish access to the 
       file or socket and free up the file descriptor for reuse
 */

 /*
    setsockopt
    getsockopt, setsockopt - get and set options on sockets

 */

 /*
    bind - bind a name to a socket
 */

 /*
    listen - listen for connections on a socket
 */

 /*
    connect - initiate a connection on a socket
 */

 /*
    accept, accept4 - accept a connection on a socket
 */ 

 /*
    send, sendto, sendmsg - send a message on a socket
 */ 

 /*
    read - read from a file descriptor
 */ 

 /*
    At       Server                     Client
       
        create   Socket            create   Socket
                  ↑ ↓                        ↑ ↓
                  ↑ ↓                        ↑ ↓  
               setsockopt                    ↑ ↓    
                  ↑ ↓                        ↑ ↓
                  ↑ ↓                        ↑ ↓          
                 bind                        ↑ ↓      
                  ↑ ↓                        ↑ ↓
                  ↑ ↓                        ↑ ↓          
                 listen ⇄ ⇄ ⇄ ⇄ ⇄ connect ⇄  ↑ ↓                    
                  ↑ ↓                        ↑ ↓
                  ↑ ↓                        ↑ ↓          
                 accept                      ↑ ↓      
                  ↑ ↓                        ↑ ↓
                  ↑ ↓                        ↑ ↓          
             send /receive ⇄ ⇄ ⇄ ⇄ ⇄ ⇄ ⇄ send /receive 

 */


 /* Address identifies a socket endpoint in a particular communication domain
    IPv4 Internet domain ( AF_INET ), a socket address is represented by 
      a sockaddr_in structure:

      struct in_addr { in_addr_t     s_addr; };         // IPv4 address

      struct sockaddr_in {
                           sa_family_t     sin_family;  // address family
                           in_port_t       sin_port;    // port number
                           struct in_addr sin_addr;     // IPv4 address
                         };
 */


 /* Linux Programmer's Manual
    manual or man page
   
    man socket
    socket - create an endpoint for communication

    man getaddrinfo

 */

 /* Addressing: machine's network address helps us identify the computer on the 
      network we wish to contact, and the service helps us identify the particular 
      process on the computer

    Byte Ordering: big and little endian

    APIs for converting between the processor byte order and the network byte order
 */



 /* Textbook: W. Richard Stevens, Advanced Programming in the UNIX Environment, 
      Pearson Education
 */
 /*
          RIP - Richard Stevens, Rajeev Motwani
 */
