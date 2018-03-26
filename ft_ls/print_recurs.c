/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recurs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:13:35 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 19:13:35 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_recurs2(t_param lst_pr, char *path)
{
	DIR		*dir;
	t_lst	*files;
	char	*a;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		a = ft_strjoin(path, "/");
		while (1)
			if (!(get_elem(&files, readdir(dir), a, lst_pr)))
				break ;
		closedir(dir);
		free(a);
		if (files)
			print_fie(files, lst_pr, 1);
		files = NULL;
	}
	else
		ft_error_name("ft_ls: ", path, 0);
}

int		ft_cheack(t_lst *file, t_param lst_pr)
{
	if (file->content && file->path && \
			S_ISDIR(file->st_mode) && \
			ft_strcmp(".", file->content) && \
			ft_strcmp("..", file->content) && \
			!(lst_pr.a == 0 && file->content[0] == '.'))
		return (1);
	return (0);
}

void	ft_print_recurs1(t_lst *file, t_param lst_pr)
{
	int		num;

	if (file->prev)
	{
		go_to_start(&file);
		num = file->prev->num;
		while (num != file->num)
		{
			ft_cheack(file, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
			file = file->next;
		}
	}
	ft_cheack(file, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
}

void	ft_print_recurs1r(t_lst *file, t_param lst_pr)
{
	int		num;

	if (file->next)
	{
		go_to_start(&file);
		num = file->next->num;
		while (num != file->num)
		{
			ft_cheack(file, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
			file = file->prev;
		}
	}
	ft_cheack(file, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
}
