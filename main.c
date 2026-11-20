#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;
    char *line;
    size_t  ln;

    ln = 0;
    if(argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if(fd < 0)
        {
            perror("open");
            return (-1);
        }
        printf("===READ FROM FILE===\n");
    }
    else
    {
        fd = 0;
        printf("===READ FROM STDIN===\n");
        printf("pleas Enter a text:\n");
    }
    while((line = get_next_line(fd)) != NULL)
    {
        printf("line[%zu]: %s", ln, line);
        ln++;
        free(line);
    }
    if(fd > 0)
        close(fd);
    return (0);
}