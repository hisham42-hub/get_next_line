#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

// # ifndef BUFFER_SIZE
// # define BUFFER_SIZE 42
// # endif
typedef struct s_list
{
    void          *content;
    struct s_list   *next;
}   t_list;

int     ft_strchr (char *content, char c);
size_t  ft_linelen (t_list *chunks);
t_list  *ft_lstnew(void *content);
t_list  *ft_lstlast(t_list *lst);
void    *del (t_list *lst);
char    *read_to_buffer (int fd, int *bytes_read);
t_list  *update_chunks(t_list *chunks);
char    *extract_line(t_list *chunks);
t_list  *read_to_chunks(int fd, t_list *chunks);
char    *get_next_line(int fd);

#endif