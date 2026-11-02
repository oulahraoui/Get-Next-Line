/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulahra <ooulahra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:51:11 by ooulahra          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:21 by ooulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef GET_NEXT_LINE_H
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct s_list{
	char		*str;
	struct s_list	*next;
}	t_list;

t_list		*findlastnode(t_list *lst);
void		add_node(t_list **lst, int fd);
void		append_list(t_list **lst, char *buf);
int		newline(t_list *lst);
char		*get_next_line(int fd);
int		len_n(t_list *lst);
void		ft_free_it(t_list **lst, t_list *clean, char *buf);
void		copy_str(t_list *lst, char *s);

#endif