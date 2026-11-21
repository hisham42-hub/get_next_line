/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.h                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: hsalahal <hsalahal@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 18:23:49 by hsalahal         #+#    #+#              */
/*   Updated: 2026/11/21 03:59:02 by hsalahal        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

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
char	*get_next_line(int fd);

#endif
