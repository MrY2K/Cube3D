

#include "../src/lib/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int line_num = 1;

	// Test 1: Read from a test file
	printf("=== TEST 1: Reading from test_file.txt ===\n");
	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open test_file.txt");
		return 1;
	}

	while ((line = get_next_non_empty_line_no_nl(fd)) != NULL)
	{
		printf("Line %d: [%s]\n", line_num, line);
		line_num++;
		free(line);
	}
	close(fd);

	printf("\n=== TEST 2: Reading from stdin (type lines, Ctrl+D to end) ===\n");
	printf("Type some lines with empty lines in between:\n");
	
	line_num = 1;
	while ((line = get_next_non_empty_line_no_nl(0)) != NULL)
	{
		printf("Line %d: [%s]\n", line_num, line);
		line_num++;
		free(line);
	}

	printf("\n=== All tests completed ===\n");
	return 0;
}