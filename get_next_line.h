#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

typedef struct s_list
{
    void          *content;
    struct s_list   *next;
}   t_list;

char    *ft_readbuffer (int fd, size_t *bytes_read);
int     ft_newline(t_list *chunks);
t_list  *ft_lstnew(char *content);
void    ft_lstaddback(t_list **lst, t_list *node);
char    *update_chunks(t_list *chunks);
char    *extract_line(t_list *chunks);
t_list  *read_to_chunks(int fd, t_list *chunks);
char    *get_next_line(int fd);

#endif