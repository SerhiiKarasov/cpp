#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define TFTP_PORT 69
#define BSIZE 600
#define MODE "octet"
#define OP_RRQ 1
#define OP_DATA 3
#define OP_ACK 4
#define OP_ERROR 5

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	struct hostent *host;
	char buffer[BSIZE], *p;
	int count;
	socklen_t server_len;

	if(argc != 3)
	{
		fprintf(stderr, "usage: %s hostname filename \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	host = gethostbyname(argv[1]);
	if(host == NULL)
	{
		fprintf(stderr, "unknown host: %s\n", argv[1] );
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
	server.sin_port = htons(TFTP_PORT);
	*(short *) buffer = htons(OP_RRQ);
	p = buffer + 2;
	strcpy(p, argv[2]);
	p += strlen(argv[2]) + 1;
	strcpy(p, MODE);
	p +=strlen(MODE) + 1;
	count = sendto(sock, buffer, p-buffer, 0,(struct sockaddr *)&server, sizeof server);


	do
	{
		server_len = sizeof server;
		count = recvfrom(sock, buffer, BSIZE, 0, (struct sockaddr *)&server, &server_len);
		if(ntohs(*(short *)buffer)==OP_ERROR)
		{
			fprintf(stderr, "rcat: %s\n", buffer + 4);
		}
		else
		{
			write(1 , buffer + 4, count - 4);
			*(short *) buffer = htons(OP_ACK);
			sendto(sock, buffer, 4, 0, (struct sockaddr *)&server, sizeof server);
		}
	} while (count == 516);

	return 0;

}


