/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.h                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: hsalahal <hsalahal@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 18:23:49 by hsalahal         #+#    #+#              */
/*   Updated: 2026/11/19 10:49:35 by hsalahal        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif

// # include <stdlib.h>
// # include <unistd.h>

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }	t_list;

// typedef struct s_gnl
// {
// 	t_list	*head;
// 	t_list	*tail;
// 	size_t	start;
// }	t_gnl;

// char	*get_next_line(int fd);
// int		has_nl_from(char *s, size_t start);
// size_t	gnl_linelen(t_gnl *gnl);
// t_list	*gnl_new_node(char *content);
// void	*gnl_clear(t_gnl *gnl);

// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strchr(char *content, char c);
size_t	ft_linelen(t_list *chunks);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	*del(t_list *lst);
char	*read_to_buffer(int fd, ssize_t *bytes_read);
t_list	*update_chunks(t_list *chunks);
char	*extract_line(t_list *chunks);
t_list	*read_to_chunks(int fd, t_list *chunks);
char	*get_next_line(int fd);

#endif
