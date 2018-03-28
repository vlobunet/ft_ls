/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:52:01 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 18:52:03 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_date(time_t date)
{
	char	*str1;
	char	*st_sub;
	char	*st;
	char	*st_j;
	time_t	t;

	t = time(0);
	str1 = ctime(&date);
	if ((t - 15778463) > date || t < date)
	{
		st_sub = ft_strsub(str1, 4, 6);
		st = ft_strsub(str1, 20, 4);
		st_j = ft_strjoin(st_sub, "  ");
		str1 = ft_strjoin(st_j, st);
		ft_strdel(&st);
		ft_strdel(&st_sub);
		ft_strdel(&st_j);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putchar(' ');
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void	print_error_el(t_lst *lst_err, t_param pr)
{
	DIR		*d;
	int		num;

	pr.color == 1 ? ft_putstr(C_ERROR) : 0;
	if (lst_err->next)
	{
		while (ft_strcmp(lst_err->content, lst_err->next->content) < 0)
			lst_err = lst_err->next;
		lst_err = lst_err->next;
		num = lst_err->prev->num;
		while (num != lst_err->num)
		{
			if ((d = opendir(lst_err->content)) == NULL && errno != ENOTDIR)
				ft_error_name("ft_ls: ", lst_err->content, 0);
			lst_err = lst_err->next;
		}
	}
	if ((d = opendir(lst_err->content)) == NULL && errno != ENOTDIR)
		ft_error_name("ft_ls: ", lst_err->content, 0);
	ft_putstr(C_RESET);
	ft_lstdel_el(&lst_err);
}

void	ft_error_name(char *name, char *error, int ex)
{
	ft_putstr(name);
	perror(error);
	ex ? exit(EXIT_FAILURE) : 0;
}

void	error_arg(char arg)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(arg);
	ft_putstr("\nusage: ft_ls [-Rafglrtu1] [file ...]\n");
	exit(EXIT_FAILURE);
}
