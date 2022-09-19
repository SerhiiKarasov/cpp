#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

constexpr uint32_t PORT = 8080;

int main()
{
	uint32_t server_fd;
	uint32_t new_socket;
	uint32_t value_read;
	uint32_t opt = 1;
	struct sockaddr_in address;
	uint32_t address_length = sizeof(address);
	char buffer[1024] = {0};
	const std::string sample_message = "Response from server";

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socker failed");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

	if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if(listen(server_fd,3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	if((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&address_length))<0)
	{
		perror("accept failed");
		exit(EXIT_FAILURE);
	}
	value_read = read(new_socket, buffer, 1024);
	printf("%s\n", buffer);
	send(new_socket, sample_message.c_str(), sample_message.size(), 0);
	printf("Hello message sent\n");
	close(new_socket);
	shutdown(server_fd, SHUT_RDWR);
}