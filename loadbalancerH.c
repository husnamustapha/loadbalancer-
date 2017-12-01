#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main() { 
	int socket_desc,client_sock,c,read_size,serversocket1,serversocket2;
	struct sockaddr_in loadbalancer,client,server1,server2;
	char client_message[3000];

	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1) {
		printf("cant create socket");
	}
	puts("loadbalancer socket created");
loadbalancer.sin_family=AF_INET;
loadbalancer.sin_addr.s_addr=INADDR_ANY;
loadbalancer.sin_port=htons(1000);

if(bind(socket_desc,(struct sockaddr *)&loadbalancer,sizeof(loadbalancer))<0) {
perror("fail to bind the socket to server");
return 1;
}

puts("bind done");

listen(socket_desc,3);	

puts("waiting for incoming connection");
c = sizeof(struct sockaddr_in);
client_sock=accept(socket_desc,(struct sockaddr *)&client, (socklen_t *)&c);
if(client_sock<0) {
perror("accept failed");
return 1; 
}
puts ("connection accepted");

read_size= recv(client_sock,client_message,3000,0);
if(strcmp(client_message,"morning")==0) {
	serversocket1=socket(AF_INET,SOCK_STREAM,0);
	server1.sin_family=AF_INET;
	server1.sin_addr.s_addr=inet_addr("192.168.80.133");
	server1.sin_port=htons(3000);
	if(connect(serversocket1,(struct sockaddr *)&server1,sizeof(server1))<0) {
	perror("fail to connect to loadbalancer");
	return 1;
	}

	if(send(serversocket1,client_message,strlen(client_message),0)<0) {
	puts("fail to send");
	return 1;
	}
close(serversocket1);
} else if(strcmp(client_message,"night")==0) {

	serversocket2=socket(AF_INET,SOCK_STREAM,0);
        server2.sin_family=AF_INET;
        server2.sin_addr.s_addr=inet_addr("192.168.80.136");
        server2.sin_port=htons(4000);
        if(connect(serversocket2,(struct sockaddr *)&server2,sizeof(server2))<0) {
        perror("fail to connect to loadbalancer");
        return 1; 
        }
 
	if(send(serversocket2,client_message,strlen(client_message),0)<0) {
        puts("fail to send");
        return 1;
        }
close(serversocket2);
} else { printf("error message not server");
}
}
