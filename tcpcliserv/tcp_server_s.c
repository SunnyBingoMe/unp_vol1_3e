/*
 * =====================================================================================
 *
 *       Filename:  tcp_server_s.c
 *
 *    Description:  updating server
 *
 *        Version:  1.0
 *        Created:  01/18/2013 09:30:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BinSun#mail.com (http://blog.SunnyBoy.Me)
 *   Organization:  BTH
 *
 * =====================================================================================
 */

#include "unp.h"
#include "sigchldwaitpid.c"

int main(int argc, char *argv[])
{
	int 		h_listen, h_connection, listen_port = SERV_PORT;
	pid_t		child_pid;
	socklen_t	client_length;
	struct sockaddr_in client_addr, server_addr;

	h_listen = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(listen_port);

	Bind(h_listen, (SA *) &server_addr, sizeof(server_addr));

	Listen(h_listen, LISTENQ);

	Signal(SIGCHLD, sig_chld);

	for(; ; ){
		client_length = sizeof(client_addr);
		h_connection = Accept(h_listen, (SA *) &client_addr, &client_length);
		if ( (child_pid = Fork())==0 ){
			Close(h_listen);
			str_echo(h_connection);
			exit(0);
		}else{
			Close(h_connection);
		}
	}
}

