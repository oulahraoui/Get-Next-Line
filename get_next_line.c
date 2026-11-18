/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulahra <ooulahra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:03:30 by ooulahra          #+#    #+#             */
/*   Updated: 2026/11/18 14:15:31 by ooulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next_list(t_list **lst, size_t size)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(size + 1);
	clean = malloc(sizeof(t_list));
	last = findlastnode(*lst);
	if (!buf || !clean)
		return ;
	i = 0;
	while (last->str[i] && last->str[i] != '\n')
		++i;
	if (last->str[i] == '\n')
		++i;
	j = 0;
	while (last->str[i])
		buf[j++] = last->str[i++];
	buf[j] = '\0';
	clean->str = buf;
	clean->next = NULL;
	ft_free_it(lst, clean, buf);
}

char	*get_line(t_list *lst)
{
	int		len;
	char	*buffer;

	len = len_n(lst);
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	copy_str(lst, buffer);
	return (buffer);
}

void	append_list(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*last;

	last = findlastnode(*lst);
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buf);
		return ;
	}
	if (!last)
		*lst = new;
	else
		last->next = new;
	new->str = buf;
	new->next = NULL;
}

void	add_node(t_list **lst, int fd, size_t size)
{
	int		read_bytes;
	char	*buf_str;

	while (!newline(*lst))
	{
		buf_str = malloc(size + 1);
		if (!buf_str)
			return ;
		read_bytes = read(fd, buf_str, size);
		if (read_bytes <= 0)
		{
			free(buf_str);
			return ;
		}
		buf_str[read_bytes] = '\0';
		append_list(lst, buf_str);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	size_t			bff_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	bff_size = (size_t)BUFFER_SIZE;
	add_node(&list, fd, bff_size);
	if (!list)
		return (NULL);
	line = get_line(list);
	if (!line)
		return (NULL);
	get_next_list(&list, bff_size);
	return (line);
}
