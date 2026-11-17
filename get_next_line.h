/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulahra <ooulahra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:51:11 by ooulahra          #+#    #+#             */
/*   Updated: 2026/11/17 21:10:51 by ooulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char				*str;
	struct s_list		*next;
}	t_list;

t_list		*findlastnode(t_list *lst);
void		add_node(t_list **lst, int fd, size_t size);
void		append_list(t_list **lst, char *buf);
char		*get_next_line(int fd);
void		ft_free_it(t_list **lst, t_list *clean, char *buf);
void		copy_str(t_list *lst, char *s);
int			len_n(t_list *lst);
int			newline(t_list *lst);

#endif