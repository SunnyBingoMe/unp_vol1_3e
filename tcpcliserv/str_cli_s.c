/*
 * =====================================================================================
 *
 *       Filename:  str_cli_s.c
 *
 *    Description:  p thread
 *
 *        Version:  1.0
 *        Created:  02/02/2013 09:44:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BinSun#mail.com (http://blog.SunnyBoy.Me)
 *   Organization:  BTH
 *
 * =====================================================================================
 */

#include "unpthread.h"

void *copyToServer (void *);

static int sockfd;
static FILE *fp;

void str_cli(FILE *fp_arg, int sockfd_arg)
{
	char		recvLine[MAXLINE];
	pthread_t	tid;
	sockfd = sockfd_arg;
	fp = fp_arg;

	Pthread_create(&tid, NULL, copyToServer, NULL);

	while (Readline(sockfd, recvLine, MAXLINE) > 0){
		Fputs(recvLine, stdout);
	}
}

void *copyToServer(void *arg)
{
	char sendLine[MAXLINE];

	while (Fgets(sendLine, MAXLINE, fp) != NULL){
		Writen(sockfd, sendLine, strlen(sendLine));
	}

	Shutdown(sockfd, SHUT_WR);
	
	return(NULL);
}

