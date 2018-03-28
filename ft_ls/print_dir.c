/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:12:29 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/28 18:12:33 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_elem(char *content, t_lst **lst, int i, t_param lst_pr)
{
	ft_lstadd_s(lst, content);
	ft_lstad(lst, ft_lstnew_el(i++, content, lst_pr, ""));
}

void	print_dir_2(t_lst *lst_dir, t_lst **file, t_param param, int m)
{
	DIR		*dir;
	char	*s;
	char	*a;

	dir = opendir(lst_dir->content);
	a = ft_strjoin(lst_dir->path, "/");
	while (1)
		if (!(get_elem(file, readdir(dir), a, param)))
			break ;
	free(a);
	closedir(dir);
	if (file)
	{
		s = ft_strjoin(lst_dir->content, ":");
		m ? ft_putendl(s) : NULL;
		free(s);
		print_fie(*file, param, 1);
	}
}

void	print_dir(t_lst *lst_dir, t_param param, int m)
{
	t_lst	*file;
	int		num;

	file = NULL;
	if (lst_dir->next)
	{
		lst_dir = lst_dir->prev;
		(param.f == 0 && param.t == 0 && param.u == 0) ? \
		go_to_start(&lst_dir) : 0;
		num = (lst_dir->prev ? lst_dir->prev->num : lst_dir->num);
		while (num != lst_dir->num)
		{
			print_dir_2(lst_dir, &file, param, m);
			ft_putchar('\n');
			file = NULL;
			lst_dir = lst_dir->next;
		}
	}
	print_dir_2(lst_dir, &file, param, m);
	ft_lstdel_el(&lst_dir);
}

void	print_dirr(t_lst *lst_dir, t_param param, int m)
{
	t_lst	*file;
	int		num;

	file = NULL;
	if (lst_dir->next)
	{
		(param.f == 0 && param.t == 0 && param.u == 0) ? \
		go_to_start(&lst_dir) : 0;
		lst_dir = lst_dir->prev;
		num = (lst_dir->prev ? lst_dir->next->num : lst_dir->num);
		while (num != lst_dir->num)
		{
			print_dir_2(lst_dir, &file, param, m);
			ft_putchar('\n');
			file = NULL;
			lst_dir = lst_dir->prev;
		}
	}
	print_dir_2(lst_dir, &file, param, m);
	ft_lstdel_el(&lst_dir);
}
