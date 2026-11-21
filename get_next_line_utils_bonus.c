/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils_bonus.c                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: hsalahal <hsalahal@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 03:22:26 by hsalahal         #+#    #+#              */
/*   Updated: 2026/11/21 03:58:58 by hsalahal        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *content, char c)
{
	if (!content)
		return (0);
	while (*content)
	{
		if (*content == c)
			return (1);
		content++;
	}
	return (0);
}

size_t	ft_linelen(t_list *chunks)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!chunks)
		return (i);
	while (chunks)
	{
		j = 0;
		while (((char *) chunks->content)[j])
		{
			i++;
			if (((char *) chunks->content)[j] == '\n')
				return (i);
			j++;
		}
		chunks = chunks->next;
	}
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(content);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	*del(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
	return (NULL);
}
