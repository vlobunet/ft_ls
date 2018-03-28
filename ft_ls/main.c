/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:46:56 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 18:46:58 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int g_count = 1;

int		get_elem(t_lst **lst, struct dirent *file, char *path, t_param param)
{
	if (!file)
		return (0);
	if (lst)
	{
		if (param.f == 0)
			ft_lstadd_s(lst, file->d_name);
		ft_lstad(lst, ft_lstnew_el(g_count++, file->d_name, param, path));
	}
	else
		ft_lstad(lst, ft_lstnew_el(g_count++, file->d_name, param, path));
	return (1);
}

int		s1(char *content, t_lst **file, t_lst **dir, t_param lst_pr)
{
	DIR			*d;

	d = opendir(content);
	if (d == NULL && errno != ENOTDIR)
		return (0);
	else if (d == NULL && errno == ENOTDIR)
	{
		if (lst_pr.f == 0)
			ft_lstadd_s(file, content);
		ft_lstad(file, ft_lstnew_el(g_count++, content, lst_pr, ""));
	}
	else if (d != NULL)
	{
		if (lst_pr.f == 0)
			ft_lstadd_s(dir, content);
		ft_lstad(dir, ft_lstnew_el(g_count++, content, lst_pr, ""));
		closedir(d);
	}
	ft_strdel(&content);
	return (1);
}

void	core(t_param lst_pr, t_lst *lst_dr, int m)
{
	t_lst	*lst_file;
	t_lst	*lst_dir;
	t_lst	*lst_err;
	int		num;

	lst_file = NULL;
	lst_dir = NULL;
	lst_err = NULL;
	num = (lst_dr->prev ? lst_dr->prev->num : lst_dr->num);
	while (num != lst_dr->num)
	{
		!s1(lst_dr->content, &lst_file, &lst_dir, lst_pr) ? \
			add_elem(lst_dr->content, &lst_err, g_count++, lst_pr) : 0;
		lst_dr = lst_dr->next;
	}
	!s1(lst_dr->content, &lst_file, &lst_dir, lst_pr) ? \
		add_elem(lst_dr->content, &lst_err, g_count++, lst_pr) : 0;
	lst_err ? print_error_el(lst_err, lst_pr) : 0;
	lst_pr.f == 0 && lst_file ? ft_timesort(lst_file, lst_pr) : 0;
	lst_file ? print_fie(lst_file, lst_pr, 0) : 0;
	lst_file && lst_dir ? ft_putchar('\n') : 0;
	(lst_dir && lst_pr.r) ? print_dirr(lst_dir, lst_pr, m) : 0;
	(lst_dir && !lst_pr.r) ? print_dir(lst_dir, lst_pr, m) : 0;
}

int		main(int argc, char **argv)
{
	t_lst	*lst_dr;
	t_param lst_pr;

	lst_pr = (t_param){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	lst_dr = NULL;
	if (argc > 1)
		ft_parsing(argc, argv, &lst_dr, &lst_pr);
	!lst_dr ? ft_lstad(&lst_dr, ft_lstnew_el(1, ".", lst_pr, "")) : 0;
	core(lst_pr, lst_dr, lst_dr->next ? 1 : 0);
	system("Leaks ft_ls");
	return (0);
}
