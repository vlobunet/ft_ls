/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:20:36 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/28 18:20:37 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ls_lg(t_lst *file, t_param lst_pr, int m)
{
	t_size	size;
	int		num;

	size = get_size(lst_pr, file);
	if (m)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	if (file->prev)
	{
		(lst_pr.f == 0 && lst_pr.t == 0 && lst_pr.u == 0) ? \
			go_to_start(&file) : 0;
		num = file->prev->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ls_long_file(file, lst_pr, size);
			file = file->next;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
		ls_long_file(file, lst_pr, size);
}

void	print_ls_lgr(t_lst *file, t_param lst_pr, int m)
{
	t_size	size;
	int		num;

	size = get_size(lst_pr, file);
	if (m)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	if (file->prev)
	{
		(lst_pr.f == 0 && lst_pr.t == 0 && lst_pr.u == 0) ? \
			go_to_start(&file) : 0;
		file = file->prev;
		num = file->next->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ls_long_file(file, lst_pr, size);
			file = file->prev;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
		ls_long_file(file, lst_pr, size);
}

void	print_cut(t_lst *file, t_param lst_pr)
{
	int	num;

	if (file->prev)
	{
		(lst_pr.f == 0 && lst_pr.t == 0 && lst_pr.u == 0) ? \
			go_to_start(&file) : 0;
		num = file->prev->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ft_putendl(file->content);
			file = file->next;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
		ft_putendl(file->content);
}

void	print_cutr(t_lst *file, t_param lst_pr)
{
	int	num;

	if (file->prev)
	{
		(lst_pr.f == 0 && lst_pr.t == 0 && lst_pr.u == 0) ? \
			go_to_start(&file) : 0;
		file = file->prev;
		num = file->next->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ft_putendl(file->content);
			file = file->prev;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
		ft_putendl(file->content);
}

void	print_fie(t_lst *file, t_param lst_pr, int i)
{
	(!lst_pr.f && (lst_pr.t == 1 || lst_pr.u == 1)) ? \
		ft_timesort(file, lst_pr) : 0;
	if (lst_pr.l || lst_pr.g)
		(!lst_pr.r) ? print_ls_lg(file, lst_pr, i) : \
					print_ls_lgr(file, lst_pr, i);
	else
		(!lst_pr.r) ? print_cut(file, lst_pr) : print_cutr(file, lst_pr);
	(lst_pr.re == 1) ? file = file->next : 0;
	(lst_pr.re == 1 && !lst_pr.r) ? ft_print_recurs1(file, lst_pr) : NULL;
	(lst_pr.re == 1 && lst_pr.r) ? ft_print_recurs1r(file, lst_pr) : NULL;
	ft_lstdel_el(&file);
}
