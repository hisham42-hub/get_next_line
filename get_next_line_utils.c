#include "get_next_line"

char *ft_strchr(const char *str, char c)
{
    if(!str)
        return (NULL);
    while (*str)
    {
        if(str == c)
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

    i = 0;
    while(*str)
    {
        i++;
        str++;
    }
    return(i);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t     i;
    size_t     j;
    char    *ptr;

    if(!s1 || !s2)
        return NULL;
    ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if(!ptr)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
        ptr[i++] = s1[j++];
    j = 0;
    while (s2[j])
        ptr[i++] = s2[j++];
    ptr[i] = '\0';
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
