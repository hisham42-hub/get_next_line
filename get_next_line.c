#include "get_next_line.h"

char    *update_cache(char *cache, size_t n)
{
    char    *new_cache;
    size_t  i;
    size_t  j;

    if(!cache)
        return (NULL);
    if(!cache[n])
    {
        free(cache);
        return (NULL);
    }
    new_cache = malloc((ft_strlen(cache) - n + 1) * sizeof(char));
    if(!new_cache)
    {
        free(cache);
        return (NULL);
    }
    i = n;
    j = 0;
    while(cache[i])
        new_cache[j++] = cache[i++];
    new_cache[j] = '\0';
    free(cache);
    return(new_cache);
}

char    *extract_line(char *cache)
{
    char *l_ptr;
    char *line;
    size_t len;

    if(!cache || cache[0] == '\0')
        return (NULL);
    len = 0;
    l_ptr = ft_strchr(cache, '\n');
    if(l_ptr)
        len = l_ptr - cache + 1;
    else
        len = ft_strlen(cache);
    line = malloc((len + 1) * sizeof(char));
    if(!line)
    {
        free(cache);
        return (NULL);
    }
    line = ft_strncpy(line, cache, len);
    return (line);
}

char    *read_to_cache(int fd, char *cache)
{
    char *buffer;
    int bytes_read;
    
    bytes_read = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return(NULL);
    while(!ft_strchr(cache,'\n') && bytes_read)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(buffer);
            free(cache);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        cache = ft_strjoin(cache, buffer);
    }
    free(buffer);
    return (cache);
}

char    *get_next_line(int fd)
{
    static char    *cache;
    char           *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    // if(!cache)
    // {
    //     cache = ft_intial_str("");
    //     if(!cache)
    //         return NULL;
    // }
    cache = read_to_cache(fd, cache);
    line = extract_line(cache);
    cache = update_cache(cache, ft_strlen(line));
    return (line);
}