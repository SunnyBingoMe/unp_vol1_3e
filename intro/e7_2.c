#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;
	char				serverIp[] = "127.000.000.001";

	if (argc == 2)
		memcpy(serverIp, argv[1], 16);

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	if (inet_pton(AF_INET, serverIp, &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", serverIp);

	int optValue;
	socklen_t optValueSize = sizeof(optValue);
	Getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);
	printf("SO_RCVBUF:%d.\n", optValue);
	Getsockopt(sockfd, IPPROTO_TCP, 2, &optValue, &optValueSize);
	printf("TCP_MAXSEG:%d.\n", optValue);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		printf("read bytes:%d\n", n);
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	Getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);
	printf("SO_RCVBUF:%d.\n", optValue);
	Getsockopt(sockfd, IPPROTO_TCP, 2, &optValue, &optValueSize);
	printf("TCP_MAXSEG:%d.\n", optValue);

	exit(0);
}
