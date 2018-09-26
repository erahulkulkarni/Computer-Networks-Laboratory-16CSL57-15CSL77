 /* 
   Computer Networks Laboratory (Lab) 15CSL77
   8. Using TCP/IP sockets, write a client-server program to make client sending 
        the file name and the server to send back the contents of the requested 
        file if present.
 */
 
 // Client
 #include <stdio.h> 
 #include <sys/socket.h> 
 #include <stdlib.h> 
 #include <netinet/in.h> 
 #include <string.h>
 #include <unistd.h>  
 #include <arpa/inet.h> 

 #define PORT 8080 
   
 int main( ) 
  { 
    struct sockaddr_in address; 
    int socketFd = 0, numberOfBytesRead; 
    struct sockaddr_in serv_addr; 
    char clientMessage[18] = "Hello from Client"; 
    char buffer[1024] = {'\0'}; 

    if ( ( socketFd = socket( AF_INET, SOCK_STREAM, 0) ) < 0) 
     { 
        printf("\n Socket creation error \n"); 
        return -1; 
     } 
   
    memset( &serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if( inet_pton( AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 )  
     { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
     } 
   
    if( connect( socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
     { 
        printf("\nConnection Failed \n"); 
        return -1; 
     } 

    send( socketFd , clientMessage , strlen(clientMessage) , 0 ); 
    printf("Hello message sent\n"); 

    numberOfBytesRead = read( socketFd , buffer, 1024); 

    printf("Server message = %s\n", buffer ); 
    return 0; 
 }
