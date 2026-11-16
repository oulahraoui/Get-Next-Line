/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulahra <ooulahra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:48:31 by ooulahra          #+#    #+#             */
/*   Updated: 2026/11/16 20:09:43 by ooulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*findlastnode(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	len_n(t_list *lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
				return (++len);
			len++;
			i++;
		}
		lst = lst->next;
	}
	return (len);
}

int	newline(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

void	copy_str(t_list *lst, char *s)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			s[j++] = lst->str[i];
			if (lst->str[i++] == '\n')
			{
				s[j] = '\0';
				return ;
			}
		}
		lst = lst->next;
	}
	s[j] = '\0';
}

void	ft_free_it(t_list **lst, t_list *clean, char *buf)
{
	t_list	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free((*lst));
		*lst = tmp;
	}
	*lst = NULL;
	if (clean->str[0])
		*lst = clean;
	else
	{
		free(buf);
		free(clean);
	}
}
