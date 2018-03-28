/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:53:52 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 18:53:53 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_long_file(t_lst *lst, t_param p, t_size size)
{
	ft_access(lst);
	print_lnk(lst, size.linkspace);
	if (p.g == 0)
		print_uid(lst);
	print_gid(lst);
	print_size(lst, size.size);
	print_date((*lst).date);
	(p.color == 1 && (S_ISFIFO(lst->st_mode))) ? ft_putstr(C_GREEN) : 0;
	(p.color == 1 && (S_ISCHR(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	(p.color == 1 && (S_ISDIR(lst->st_mode))) ? ft_putstr(C_FIOLE) : 0;
	(p.color == 1 && (S_ISBLK(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	(p.color == 1 && (S_ISREG(lst->st_mode))) ? ft_putstr(C_YELLO) : 0;
	(p.color == 1 && (S_ISLNK(lst->st_mode))) ? ft_putstr(C_GOLYB) : 0;
	(p.color == 1 && (S_ISFIFO(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	ft_putendl((*lst).content);
	ft_putstr(C_RESET);
}

void	go_to_start(t_lst **lst)
{
	while (strcmp((*lst)->content, (*lst)->next->content) < 0)
		*lst = (*lst)->next;
	*lst = (*lst)->next;
}
