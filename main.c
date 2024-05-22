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

// int main(int argc, char *argv[]) {
//     int fd;
//     char *file;
//     char *line;

//     if (argc < 2) {
//         fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
//         return 1;
//     }

//     file = argv[1];
//     fd = open(file, O_RDONLY);
//     if (fd < 0) {
//         perror("open");
//         return 1;
//     }

//     // Read and print lines until the first read error is simulated
//     printf("First set of lines before simulated error:\n");
//     int i = 0;
//     do {
//         line = get_next_line(fd);
//         if (line != NULL) {
//             printf("%s", line);
//             free(line);
//             i++;
//         }
//     } while (i < 2 && line != NULL);

//     // Simulate read error
//     next_read_error = 1;
//     line = get_next_line(fd);
//     if (line == NULL) {
//         printf("Read error simulated successfully.\n");
//     } else {
//         free(line);
//     }
//     next_read_error = 0;

//     // Close and reopen the file to reset the file descriptor
//     close(fd);
//     fd = open(file, O_RDONLY);
//     if (fd < 0) {
//         perror("open");
//         return 1;
//     }

//     // Read and print lines again after resetting
//     printf("Second set of lines after resetting:\n");
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }