#include	"unp.h"

void fSigPipe(int ttt){
	printf("sig pipe got.");
}

int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");

	Signal(SIGPIPE, fSigPipe);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	//str_cli(stdin, sockfd);		/* do it all */
	sleep(2);
	Write(sockfd, "hello", 5);
	sleep(2);
	Write(sockfd, "hello", 5);

	exit(0);
}
