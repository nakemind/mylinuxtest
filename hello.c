#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(int argc, char **argv)
{
 int listenfd,connfd;
 struct sockaddr_in sockaddr; 
 char buff[2048];
 int n;
 memset(&sockaddr,0,sizeof(sockaddr));
 sockaddr.sin_family = AF_INET;
 sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 sockaddr.sin_port = htons(3389); 
 
 listenfd = socket(AF_INET,SOCK_STREAM,0); 

 bind(listenfd,(struct sockaddr *)&sockaddr, sizeof(sockaddr));
 listen(listenfd,1024);

 printf("11122223333Hello word!\r\n");
 for(;;)
 {
	if((connfd=accept(listenfd,(struct sockaddr*)NULL,NULL))==-1)
	{
		printf("accpt errod\r\n");
		continue;
	}
	n =recv(connfd,buff,2048,0);
	printf("%s\r\n",buff);
	buff[n]='\0';
	close(connfd);
 }
}