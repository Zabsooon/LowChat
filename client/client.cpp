#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#include "lowchat/terminator.h"

int main() 
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2137);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	socklen_t socklen = sizeof(addr);
	ssize_t rv = connect(fd, (const struct sockaddr*)&addr, socklen);
	
	if(rv)
		Terminator::die("connect() error");

	char wbuf[4096] = "Hello this is client -> write()";
	size_t wnbyte = strlen(wbuf);

	rv = write(fd, &wbuf, wnbyte);	
	if(rv >= 0)
		Terminator::msg("Bytes of info have been sent");
	
	char rbuf[4096] = {};
	size_t rnbuf = sizeof(rbuf);
	rv = read(fd, rbuf, rnbuf - 1);
	
	close(fd);
	return 0;
}
