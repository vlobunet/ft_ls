/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:06:55 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 19:06:56 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_numlen(int num)
{
	int	i;

	i = 1;
	if (num > 9)
		while (num / 10)
		{
			i++;
			num = num / 10;
		}
	return (i);
}

void	get_size_errorhandling(t_size *size, t_lst *cur)
{
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name);
	else
		size->userspace = ft_numlen(cur->st_uid);
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name);
	else
		size->groupspace = ft_numlen(cur->st_gid);
}

void	get_size_quick(t_size *size, t_lst *lst)
{
	size->linkspace = ft_numlen(lst->st_nlink) > \
		size->linkspace ? ft_numlen(lst->st_nlink) \
		: size->linkspace;
	size->maj = ft_numlen(major(lst->st_rdev)) > size->maj \
		? ft_numlen(major(lst->st_rdev)) : size->maj;
	size->min = ft_numlen(minor(lst->st_rdev)) > size->min ? \
		ft_numlen(minor(lst->st_rdev)) : size->min;
	size->size = ft_numlen(lst->st_size) > size->size ? \
		ft_numlen(lst->st_size) : size->size;
	size->total += lst->st_blocks;
}

t_size	get_size(t_param arg, t_lst *lst)
{
	t_size	size;
	int		num;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	if (lst->prev)
	{
		num = lst->prev->num;
		while (num != lst->num)
		{
			if (!(arg.a == 0 && lst->content[0] == '.'))
			{
				get_size_quick(&size, lst);
				get_size_errorhandling(&size, lst);
			}
			lst = lst->next;
		}
	}
	if (!(arg.a == 0 && lst->content[0] == '.'))
	{
		get_size_quick(&size, lst);
		get_size_errorhandling(&size, lst);
	}
	return (size);
}
