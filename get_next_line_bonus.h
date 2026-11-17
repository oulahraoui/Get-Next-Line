/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulahra <ooulahra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:52:12 by ooulahra          #+#    #+#             */
/*   Updated: 2026/11/16 20:08:57 by ooulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

t_list		*findlastnode(t_list *lst);
void		add_node(t_list **lst, int fd);
void		append_list(t_list **lst, char *buf, int fd);
void		copy_str(t_list *lst, char *s);
void		ft_free_it(t_list **lst, t_list *clean, char *buf);
char		*get_next_line(int fd);
int			newline(t_list *lst);
int			len_n(t_list *lst);

#endif
