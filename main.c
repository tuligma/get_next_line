#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int	fd;
	char *file;
	char *line;

	(void)argc;
	file = argv[1];
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}