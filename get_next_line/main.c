#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s;

	s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	free(s);
}
