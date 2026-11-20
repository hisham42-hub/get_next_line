#include "get_next_line_bonus.h"

static *char extract_line
{
    char *line;

    return(line);
}

static char *read_to_buffer(int fd, ssize_t *bytes_read)
{
    char *b;
    int  i;

    b = malloc((BUFFER_SIZE == 1) * 1025 + (BUFFER_SIZE != 1) * (BUFFER_SIZE + 1));
    if(!b)
        return (NULL);
    if(BUFFER_SIZE != 1)
    {
        *bytes_read = read(fd, b, BUFFER_SIZE);
        if(*bytes_read <= 0)
            return(free(b), NULL);
        return(b[*bytes_read] = '\0', b);
    }
}

static t_list *read_to_chunks(int fd, t_list *chunks)
{
    char *buffer;
    ssize_t bytes_read;
    t_list *last;
    t_list *node;

    last = ft_lstlast(chunks);
    while(!last || !ft_strchr(last->content, '\n'))
    {
        buffer = read_to_buffer(fd, &bytes_read);
        if(!buffer && bytes_read == -1)
            return(del(chunks));
        if(!buffer && bytes_read == 0)
            break;
        node = ft_lstnew(buffer);
        if(!node)
            return(del(chunks));
        if(!chunks)
            chunks = node;
        else
            last->next = node;
        last = node;
    }
    return (chunks);
}

char *get_next_line_bonus(fd)
{
    static t_list   *chunks[1024];
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
        return NULL;
    chunks[fd] = read_to_chunks(fd, chunks[fd]);
    if(!chunks[fd])
        return (NULL);
    line = extract_line(chunks[fd]);
    if(!line)
    {
        free(line);
        return(del(chunks[fd]));
    }
    chunks[fd] = update_chunks(chunks[fd]);
    if(chunks[fd] || !((char *)chunks[fd]->content)[0])
    {
        temp = chunks[fd]->next;
        free(chunks[fd]->content);
        free(chunks[fd]);
        chunks[fd] = temp;
    }
    return(line);
}