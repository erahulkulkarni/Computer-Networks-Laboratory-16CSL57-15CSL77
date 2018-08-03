/* 
	Computer Networks Laboratory (Lab) 15CSL77
	8. Using TCP/IP sockets, write a client-server program to make client sending the file name 
	and the server to send back the contents of the requested file if present.
*/

/* Process-to-process delivery needs two identifiers, IP address and the port number, 
   at each end to make a connection.   

   IP to recognize computer on network, after which recognize process on the computer
   using port number

   IP Address: uniquely defines a host on the Internet, logical addressing, hierarchical

   Socket Addresses: combination of an IP address and a port number  

   Now turning to UNIX (every thing looks like a file!)
   Sockets can be used for interprocess communication
   Socket is a type of file used for network communication between processes, network IPC
   IPC Inter 
   Or for non-network communication between processes on a single host

   UNIX domain sockets are full duplex by default   
*/

/* Linux Programmer's Manual
   man socket
   socket - create an endpoint for communication

   man getaddrinfo

*/




/* Textbook: Behrouz Forouzon - Data Communications and Networking, McGraw Hill Edition 
   W. Richard Stevens, Advanced Programming in the UNIX Environment, Pearson Education
*/
