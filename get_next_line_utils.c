#include "get_next_line"

int ft_newline(t_list *chunks)
{
    char *content;
    t_list *temp_lst;

    if(!chunk)
        return (0);
    temp_lst = chunk;
    while (temp_lst)
    {
        content = (char *)temp_lst->content;
        while(*content)
        {
            if(*content == '\n')
                return (1);
            content++;
        }
        temp_lst = temp_lst->next;
    }
    return (0);
}

t_list  ft_lstnew(void *content)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if(!node)
        reurn (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

t_list  *ft_lstnew(char *content)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if(!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

void    ft_lstaddback(t_list **lst, t_list *node)
{
    if(!lst || !node)
        return (NULL);
    if(!*lst)
    {
        *lst = node;
        return;
    }
    while(lst->next)
        lst = lst->next;
    lst->next = node;
}

char    *ft_readbuffer (int fd, size_t *bytes_read)
{
    char *buffer;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if(bytes_read == -1)
    {
        free(buffer)
        return (NULL);
    }
    buffer[bytes_read] = '\0';
    return (buffer);
}
