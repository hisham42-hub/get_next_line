/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: hsalahal <hsalahal@student.42abudhabi.ae> #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 18:23:52 by hsalahal         #+#    #+#              */
/*   Updated: 2026/11/19 10:55:49 by hsalahal        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h"

char	*read_to_buffer(int fd, ssize_t *bytes_read)
{
	char	*b;
	int		i;

	i = BUFFER_SIZE;
	b = malloc((i == 1) * 1025 + (i != 1) * (i + 1));
	if (!b)
		return (NULL);
	if (i != 1)
	{
		*bytes_read = read(fd, b, i);
		if (*bytes_read <= 0)
			return (free(b), NULL);
		return (b[*bytes_read] = '\0', b);
	}
	i = 0;
	*bytes_read = read(fd, &b[i], 1);
	while (i < 1023 && *bytes_read > 0 && b[i] != '\n')
		*bytes_read = read(fd, &b[++i], 1);
	if (i == 0 && *bytes_read <= 0)
		return (free(b), NULL);
	if (*bytes_read > 0 && (b[i] == '\n' || i == 1023))
		i++;
	return (b[i] = '\0', b);
}

t_list	*update_chunks(t_list *chunks)
{
	char	*content;
	size_t	i;
	size_t	j;
	t_list	*temp;

	while (chunks && !ft_strchr((chunks->content), '\n'))
	{
		temp = chunks->next;
		free(chunks->content);
		free(chunks);
		chunks = temp;
	}
	if (!chunks)
		return (NULL);
	content = chunks->content;
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	j = 0;
	if (content[i] == '\n')
		i++;
	while (content[i])
		content[j++] = content[i++];
	content[j] = '\0';
	return (chunks);
}

char	*extract_line(t_list *chunks)
{
	char	*line;
	char	*content;
	size_t	len;
	size_t	i;

	len = ft_linelen(chunks);
	if (len == 0)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (chunks && (len == 0 || line[len - 1] != '\n'))
	{
		i = 0;
		content = (char *)(chunks->content);
		while (content[i] && (len == 0 || line[len - 1] != '\n'))
			line[len++] = content[i++];
		chunks = chunks->next;
	}
	line[len] = '\0';
	return (line);
}

t_list	*read_to_chunks(int fd, t_list *chunks)
{
	char	*buffer;
	ssize_t	bytes_read;
	t_list	*node;
	t_list	*last;

	last = ft_lstlast(chunks);
	while (!last || !ft_strchr(last->content, '\n'))
	{
		buffer = read_to_buffer(fd, &bytes_read);
		if (!buffer && bytes_read == -1)
			return (del(chunks));
		else if (!buffer && bytes_read == 0)
			break ;
		node = ft_lstnew(buffer);
		if (!node)
			return (del(chunks));
		if (!chunks)
			chunks = node;
		else
			last->next = node;
		last = node;
	}
	return (chunks);
}

char	*get_next_line(int fd)
{
	static t_list	*chunks;
	t_list			*temp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunks = read_to_chunks(fd, chunks);
	if (!chunks)
		return (NULL);
	line = extract_line(chunks);
	if (!line)
	{
		chunks = del(chunks);
		return (NULL);
	}
	chunks = update_chunks(chunks);
	if (chunks && !(((char *) chunks->content)[0]))
	{
		temp = chunks->next;
		free(chunks->content);
		free(chunks);
		chunks = temp;
	}
	return (line);
}

// t_list	*read_to_chunks(int fd, t_list *chunks)
// {
// 	char	*buffer;
// 	ssize_t	bytes_read;
// 	t_list	*node;
// 	t_list	*last;

// 	last = ft_lstlast(chunks);
// 	if (last && ft_strchr(last->content, '\n'))
// 		return (chunks);
// 	while (1)
// 	{
// 		buffer = read_to_buffer(fd, &bytes_read);
// 		if (!buffer && bytes_read == -1)
// 			return (del(chunks));
// 		if (!buffer && bytes_read == 0)
// 			break ;
// 		node = ft_lstnew(buffer);
// 		if (!node)
// 			return (del(chunks));
// 		if (!chunks)
// 			chunks = node;
// 		else
// 			last->next = node;
// 		last = node;
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	return (chunks);
// }