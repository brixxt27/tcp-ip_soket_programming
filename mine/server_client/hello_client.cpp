#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void	error_handling(char* message)
{
	std::cerr << message << std::endl;
	exit(1);
}

int	main(int argc, char* argv[])
{
	int	sock;
	struct sockaddr_in serv_addr;

	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <IP> <port>" << std::endl;
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cout << "socket() error" << std::endl;
		exit(1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // inet_addr: 문자열 기반의 IP주소를 32비트 정수형으로 변환
	// inet_addr 는 htol 함수를 호출하지 않아도 된다.
	//왜냐하면 inet_addr 함수가 반환하는 값은 네트워크 바이트 순서로 변환된 값이기 때문이다면
	serv_addr.sin_port = htons(atoi(argv[2])); // atoi: 문자열을 정수형으로 변환
	// htons: 호스트 바이트 순서를 네트워크 바이트 순서로 변환
	// htonl: 호스트 바이트 순서를 네트워크 바이트 순서로 변환
}