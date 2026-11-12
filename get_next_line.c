#include "get_next_line.h"

char    *read_to_buffer (int fd, int *bytes_read)
{
    char *buffer;

    *bytes_read = -1;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buffer)
        return (NULL);
    *bytes_read = read(fd, buffer, BUFFER_SIZE);
    if(*bytes_read <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[*bytes_read] = '\0';
    return (buffer);
}

t_list    *update_chunks(t_list *chunks)
{
    char *content;
    size_t i;
    size_t j;
    t_list *temp;

    while(chunks && !ft_strchr((chunks->content), '\n'))
    {
        temp = chunks->next;
        free(chunks->content);
        free(chunks);
        chunks = temp;
    }
    if(!chunks)
        return (NULL);
    content = chunks->content;
    i = 0;
    while(content[i] && content[i] != '\n')
        i++;
    j = 0;
    i++;
    while(content[i])
        content[j++] = content[i++];
    content[j] = '\0';
    return(chunks);
}

char    *extract_line(t_list *chunks)
{
    char *line;
    char *content;
    size_t len;
    size_t i;

    len = ft_linelen(chunks);
    if(len == 0)
        return NULL;
    line = malloc((len + 1) * sizeof(char));
    if(!line)
        return (NULL);
    len = 0;
    while(chunks && (len == 0 || line[len - 1] != '\n'))
    {
        i = 0;
        content = (char *)(chunks->content);
        while(content[i] && (len == 0 || line[len - 1] != '\n'))
            line[len++] = content[i++];
        chunks = chunks->next;
    }
    line[len] = '\0';
    return (line);
}

t_list    *read_to_chunks(int fd, t_list *chunks)
{
    char *buffer;
    int bytes_read;
    t_list *node;
    t_list *last;

    last = ft_lstlast(chunks);
    while(!last || !ft_strchr(last->content, '\n'))
    {
        buffer = read_to_buffer(fd, &bytes_read);
        if(!buffer && bytes_read == -1)
            return (del(chunks));
        else if (!buffer && bytes_read == 0)
            break;
        node = ft_lstnew(buffer);
        if(!node)
            return(del(chunks));
        if (!chunks)
            chunks = node;
        else
            last->next = node;
        last = node;
    }
    return (chunks);
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
    if(!line)
    {
        chunks = del(chunks);
        return (NULL);
    }
    chunks = update_chunks(chunks);
    return (line);
}
