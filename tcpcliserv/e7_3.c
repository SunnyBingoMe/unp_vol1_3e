#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, serverPort = 7;
	struct sockaddr_in	servaddr;
	char				serverIp[] = "127.000.000.001";

	if (argc == 2)
		memcpy(serverIp, argv[1], 16);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(serverPort);
	Inet_pton(AF_INET, serverIp, &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	str_cli(stdin, sockfd);		/* do it all */

	struct linger tLinger; tLinger.l_onoff = 1; tLinger.l_linger = 3;
	socklen_t optValueSize = sizeof(struct linger);
	Setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &tLinger, optValueSize);

	/*printf("close returned:%d.\n", close(sockfd));*/

	exit(0);
}
