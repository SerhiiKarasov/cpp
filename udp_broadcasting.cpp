#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>


#define UPDATE_PORT 2066

typedef struct packet
{
	char text[64];
	int x;
	int y;
} Packet;

void display_update(Packet p);

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int client_len, yes = 1;
	Packet pkt;

	initscr();
	cbreak();
	noecho();

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *) &yes, sizeof yes);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(UPDATE_PORT);

	if( bind(sock, (struct sockaddr *)&server, sizeof server)<0)
	{
		printw("server: bind failed\n");
		refresh();
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = 0xffffffff;
	server.sin_port = htons(UPDATE_PORT);

	if (fork())
	{
		if (argc > 1)
			strcpy(pkt.text, argv[1]);
		else
			gethostname(pkt.text, 64);
		pkt.x = 40;
		pkt.y = 12;

		while (1)
		{
			pkt.x = rand() % 80;
			pkt.y = rand() % 80;

			sendto(sock, (char *)&pkt, sizeof pkt, 0, (struct sockaddr *)&server, sizeof server);
			sleep(1);
		}
	}
	else
	{
		while (1)
		{
			client_len = sizeof client;
			recvfrom(sock, (char *) &pkt, sizeof pkt, 0,
					(struct sockaddr *) &client, (socklen_t*)&client_len);
			display_update(pkt);
			return 0;
		}
	}
}

void display_update(Packet p)
{
#define 	TSIZE 	50
	static char table[TSIZE][64];
	static int entries = 0;
	int i, found;
	for(i = 0, found = 0; i < entries; i++)
	{
		if(strcmp(p.text, table[i])== 0)
		{
			found = 1;
			break;
		}
	}
	if(!found)
	{
		if (entries == TSIZE)
		{
			return;
		}
		strcpy(table[entries], p.text);
		i = entries++;
	}

	move(i, 1);
	printw("%16s %4d %4d", p.text, p.x, p.y);

}
