#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(){
int sockett;
struct sockaddr_in server;
char mess[3000];

sockett=socket(AF_INET,SOCK_STREAM,0);
if(sockett==-1){
printf("could not create socket");

}
puts("socket created");
server.sin_addr.s_addr=inet_addr("192.168.94.129"); //IP ADDRESS LOAD BALANCER CLIENT
server.sin_family=AF_INET;
server.sin_port=htons(1000);

if(connect(sockett,(struct sockaddr *)&server,sizeof(server))<0){
perror("fail to connect to loadbalancer");
return 1;
}

printf("write a message to send to server :");
scanf("%s",mess);
if(send(sockett,mess,strlen(mess),0)<0){
puts("cannot/fail to sent");
return 1;
}
close(sockett);
return 0;
}




