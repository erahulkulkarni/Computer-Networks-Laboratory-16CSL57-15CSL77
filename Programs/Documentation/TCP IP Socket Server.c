 /* 
   Computer Networks Laboratory (Lab) 15CSL77
   8. Using TCP/IP sockets, write a client-server program to make client sending 
        the file name and the server to send back the contents of the requested 
        file if present.
 */

 // Server
 #include <unistd.h>  
 #include <stdio.h> 
 #include <sys/socket.h> 
 #include <stdlib.h> 
 #include <netinet/in.h> 
 #include <string.h> 
 #define PORT 8080 

 int main() 
  { 
    int serverFd, newSocket, numberOfBytesRead; 
    struct sockaddr_in address; 
    int option = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char serverMessage[18] = "Hello from Server"; 
       
    // Creating socket file descriptor 
    if ( ( serverFd = socket( AF_INET, SOCK_STREAM, 0) ) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if ( setsockopt ( serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                &option, sizeof(option))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if ( bind ( serverFd, (struct sockaddr *)&address, sizeof(address))<0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    if ( listen (serverFd, 3) < 0 ) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    if ( ( newSocket = accept( serverFd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen) )<0 ) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    numberOfBytesRead = read( newSocket , buffer, 1024); 
    printf("Client message = %s\n",buffer ); 

    send( newSocket , serverMessage , strlen(serverMessage) , 0 ); 

    printf("Hello message sent\n"); 

    return 0; 
 } 
