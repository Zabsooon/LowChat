#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

#include "terminator.h"

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



	return 0;
}
