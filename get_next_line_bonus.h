#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list{
    void *content;
    struct s_list next;
}t_list;

int     ft_strchr(char *s, char c);
t_list  *ft_lstlast(t_list *lst);
char    *get_next_line(int fd);

#endif


