#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
}
