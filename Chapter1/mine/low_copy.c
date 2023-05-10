#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_MODE -1
#define BUFFER_SIZE 10

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int	open_file(char* path, int oflag, int mode)
{
	int fd;

	if (mode == NOT_MODE)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, mode);

	return fd;
}

int	read_file(int fd, char* buffer)
{
	int	fd;
	char* line;

	line = malloc(BUFFER_SIZE);
	if (line == NULL)
	{
		error_handling("malloc() error");
		exit(1);
	}

	while (1)
	{
		fd = read(fd, line, BUFFER_SIZE);
		if (fd == -1)
			return fd;
		if (fd == 0)
			break;
	}
	free(line);
}

int	main(void)
{
	int	src_file_fd;
	int	dest_file_fd;
	int	fd;

	char*	buffer;

	src_file_fd = open_file("data.txt", O_RDONLY, NOT_MODE);
	if (src_file_fd == -1)
	{
		error_handling("open() error");
	}

	fd = read_file(dest_file_fd, buffer);
	if (src_file_fd == -1)
	{
		error_handling("read() error");
	}

	dest_file_fd = open_file("copy.txt", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (dest_file_fd == -1)
	{
		error_handling("open() error");
	}

	fd = copy_text(buffer);
	if (fd == -1)
	{
		error_handling("write() error");
	}

}
