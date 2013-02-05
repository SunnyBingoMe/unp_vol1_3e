/*
 * =====================================================================================
 *
 *       Filename:  e7_1.c
 *
 *    Description:  getSockOpt()
 *
 *        Version:  1.0
 *        Created:  01/31/2013 05:06:10 PM
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
	int dSocket, optValue;
	socklen_t optValueSize = sizeof(optValue);

	dSocket = Socket(AF_INET, SOCK_STREAM, 0);
	Getsockopt(dSocket, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);
	printf("tcpRcv:%d.\n", optValue);
	Getsockopt(dSocket, SOL_SOCKET, SO_SNDBUF, &optValue, &optValueSize);
	printf("tcpSnd:%d.\n", optValue);
	optValue = 0;

	dSocket = Socket(AF_INET, SOCK_DGRAM, 0);
	Getsockopt(dSocket, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);
	printf("udpRcv:%d.\n", optValue);
	Getsockopt(dSocket, SOL_SOCKET, SO_SNDBUF, &optValue, &optValueSize);
	printf("udpSnd:%d.\n", optValue);
	optValue = 0;

	dSocket = Socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
	Getsockopt(dSocket, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);
	printf("sctpRcv:%d.\n", optValue);
	Getsockopt(dSocket, SOL_SOCKET, SO_SNDBUF, &optValue, &optValueSize);
	printf("sctpSnd:%d.\n", optValue);
	/*sctp_opt_info(dSocket, 0, SOL_SOCKET, SO_RCVBUF, &optValue, &optValueSize);*/
	/*printf("sctpRcv:%d.\n", optValue);*/
	/*sctp_opt_info(dSocket, 0, SOL_SOCKET, SO_SNDBUF, &optValue, &optValueSize);*/
	/*printf("sctpSnd:%d.\n", optValue);*/

	return 0;
}

