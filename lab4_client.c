#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr

void func(int sockfd){
char buff[MAX];
int n;
for(;;)
{bzero(buff,sizeof(buff));
	printf("Client: ");
	n=0;
	
	while((buff[n++]=getchar()) !='\n');
	write(sockfd,buff,sizeof(buff));
	bzero(buff,sizeof(buff));
	read(sockfd,buff,sizeof(buff));
	printf("\nServer: %s",buff);
	
	if((strncmp(buff,"exit",4))==0)
	{printf("Client Exit...\n");
	break;
}
}
}


int main()
{int sockfd,connfd;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
	printf("Socket Creation Failed..\n");
	exit(0);
}
else
	printf("Socket successfullt created..\n");
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("192.168.1.20");
	servaddr.sin_port=htons(PORT);
	if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0)
	{
		printf("Connection with the server failed...\n");
		exit(0);
	}
	else
		printf("Connected to the Server...\n");
	func(sockfd);
	close(sockfd);
	
}