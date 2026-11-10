#include "get_next_line"

char    *update_chunks(t_list *chunks, void (*del)(* void))
{
    char    *new_chunks;
    size_t  i;
    size_t  j;

    if(!chunks)
    {
        free(chunks);
        return (NULL);
    }
    new_chunks = chunks->next;
    del(chunks->content);
    free(chunks);
    return(new_chunks);
}

char    *extract_line(t_list *chunks)
{
    char *line;
    size_t len;

    if(!chunks)
        return (NULL);
    len = ft_strlen((char *)chuncks->content);
    line = malloc((len + 1) * sizeof(char));
    if(!line)
        return (NULL);
    line = (char *)chuncks->content
    return (line);
}

t_list    *read_to_chunks(int fd, t_list *chunks)
{
    char *buffer;
    size_t bytes_read;
    t_list *node;
    t_list *head;

    bytes_read = 1;
    while(!ft_newline(chunks) && bytes_read)
    {
        buffer = ft_readbuffer(fd,bytes_read);
        if(bytes_read == -1)
        {
            free(chunks);
            return (NULL);
        }
        node = ft_lstnew(buffer);
        if (*head)
            head = node;
        else
            ft_lstaddback(&head, node);
    }
    free(buffer);
    return (&head);
}

char    *get_next_line(int fd)
{
    static t_list    *chunks;
    char           *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    chunks = read_to_chunks(fd, chunks);
    if(!chunks)
        return NULL;
    line = extract_line(chunks);
    chunks = update_chunks(chunks);
    return (line);
}