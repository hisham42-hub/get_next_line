#include "get_next_line.h"

char *ft_strchr(const char *str, int c)
{
    if(!str)
        return (NULL);
    while (*str)
    {
        if(*str == c)
            return ((char *)str);
        str++;
    }
    if(*str == c)
        return ((char *)str);
    return (NULL);
}

size_t ft_strlen(const char *str)
{
    size_t i;
    char *s;

    if(!str)
        return(0);
    s = (char *)str;
    i = 0;
    while(*s)
    {
        i++;
        s++;
    }
    return(i);
}

char *ft_strjoin(const char *cache, const char *s2)
{
    size_t     i;
    size_t     j;
    char    *ptr;

    ptr = malloc((ft_strlen(cache) + ft_strlen(s2) + 1) * sizeof(char));
    if(!ptr)
        return (NULL);
    i = 0;
    if(cache)
    {
        j = 0;
        while (cache[j])
            ptr[i++] = cache[j++];
    }
    if(s2)
    {
        j = 0;
        while (s2[j])
            ptr[i++] = s2[j++];
        ptr[i] = '\0';
    }
    free((void *)cache);
    return(ptr);
}

char *ft_strncpy(char *ptr, const char *src, size_t n)
{
    size_t i;
    if(!ptr || !src)
        return (NULL);
    i = 0;
    while((i < n) && src[i])
    {
        ptr[i] = src[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

// char *ft_intial_str(char *str)
// {
//      char *intial;
//      size_t len;
     
//      len = ft_strlen(str);
//      intial = malloc((len + 1) * sizeof(char));
//      if(!intial)
//         return (NULL);
//     intial[0] = '\0';
//     return (intial);
// }
