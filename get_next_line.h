#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

char    *update_cache(char *cache, size_t n);
char    *extract_line(char *cache);
char    *read_to_cache(int fd, char *cache);
char    *get_next_line(int fd);
char    *ft_strchr(const char *str, char c);
size_t  ft_strlen(const char *str);
char    *ft_strncpy(char *ptr, const char *src, size_t n);
char    *ft_strjoin(const char *s1, const char *s2);
int     ft_count_newline(char *str);

#endif