#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <queue>

#include "lowchat/terminator.h"

void handle_connection(int connfd)
{
	char rbuf[4096] = {};
	while(rbuf != "close()")
	{
		read(connfd, rbuf, 4095);
		Terminator::msg(rbuf);

		char wbuf[] = "Hello this is server -> write()";
		size_t wnbyte = strlen(wbuf);
		write(connfd, &wbuf, wnbyte);
		Terminator::msg("response has been sent");
	}
}

static std::queue<std::thread> thread_queue;


int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	int val = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2137);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	int rv = bind(fd, (const sockaddr*)&addr, sizeof(addr));

	if(rv)
		Terminator::die("bind() error");

	rv = listen(fd, 20);

	if(rv)
		Terminator::die("listen() error");

	int connfd{0};
	while(true)
	{
		struct sockaddr_in client_addr = {};
		socklen_t socklen = sizeof(client_addr);
		connfd = accept(fd, (struct sockaddr*)&client_addr, &socklen);

		if(connfd != -1)
		{
			std::thread connThread(&handle_connection, connfd);
			connThread.join(); // yes... i know
		}
		int success = close(connfd);
		if(!success)
		{
			// release thread from the pool ( later to implement )
		}
	}
	return 0;
}
