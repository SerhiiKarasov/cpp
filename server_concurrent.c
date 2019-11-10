#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


extern time_t time();

char *word[] =
{ "#include \"words\"" };

#define NUM_OF_WORDS (sizeof(word)/sizeof(word[0]))
#define MAXLEN 80
#define HANGMAN_TCP_PORT 1068

void play_hangman(int in, int out)
{
	printf("HI");
}

int main(int argc, char *argv[])
{
	int sock, msgsock;
	socklen_t client_len;

	struct sockaddr_in server, client;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0)
	{
		perror("creating socket");
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(HANGMAN_TCP_PORT);

	if(bind(sock, (struct sockaddr *)&server, sizeof(server)) > 0)
	{
		perror("binding socket");
		exit(2);
	}

	listen(sock, 5);
	fprintf(stderr, "hangman server: listening...\n");


	while(1)
	{
		client_len = (socklen_t)sizeof(client);
		msgsock = accept(sock, (struct sockaddr *) &client, &client_len);

		if(msgsock < 0)
		{
			perror("accepting connection");
			exit(3);
		}

		if(fork() == 0)
		{
			close(sock);
			printf("new child pid %d, descriptor %d ", getpid(), msgsock);
			srand((int)time((time_t *)1) );
			play_hangman(msgsock, msgsock);
			printf("child (% pid) exiting\n", getpid());
			exit(0);
		}
		else
		{
			close(msgsock);
		}

		return 0;
	}
}

