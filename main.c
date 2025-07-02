#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("empty.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
}
