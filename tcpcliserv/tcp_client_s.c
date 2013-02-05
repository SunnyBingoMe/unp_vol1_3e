/*
 * =====================================================================================
 *
 *       Filename:  tcp_client_s.c
 *
 *    Description:  updating
 *
 *        Version:  1.0
 *        Created:  01/18/2013 10:52:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BinSun#mail.com (http://blog.SunnyBoy.Me)
 *   Organization:  BTH
 *
 * =====================================================================================
 */

#include "unp.h"

int main(int argc, char *argv[])
{
	int			h_connection, server_port = 7;
	struct 		sockaddr_in server_addr;
	char		server_ip[] = "127.000.000.001";
	
	if (argc == 2){
		strcpy(server_ip, argv[1]);
	}

	h_connection = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(server_port);
	Inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

	Connect(h_connection, (SA *) &server_addr, sizeof(server_addr));

	str_cli(stdin, h_connection);

	exit(0);
}

