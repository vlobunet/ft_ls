/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:12:11 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/28 18:12:16 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstdel_el(t_lst **lst)
{
	int		num;
	t_lst	*p;

	num = ((*lst)->prev ? (*lst)->prev->num : (*lst)->num);
	while (num != (*lst)->num)
	{
		p = *lst;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->next;
		ft_strdel(&p->content);
		ft_strdel(&p->path);
		free(p);
	}
	(*lst)->prev = NULL;
	(*lst)->next = NULL;
	ft_strdel(&(*lst)->content);
	ft_strdel(&(*lst)->path);
	free(*lst);
}

t_lst	*ft_lstnew_el(int num, char *str, t_param p, char *path)
{
	t_lst		*lst;
	struct stat	st;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->num = num;
	lst->content = ft_strdup(str);
	lst->path = ft_strjoin(path, str);
	lstat(lst->path, &st);
	lst->st_mode = st.st_mode;
	lst->st_nlink = st.st_nlink;
	lst->st_uid = st.st_uid;
	lst->st_gid = st.st_gid;
	lst->st_size = st.st_size;
	lst->st_blocks = st.st_blocks;
	lst->date = (p.u == 1 ? st.st_atime : st.st_mtime);
	lst->st_rdev = st.st_rdev;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void	ft_lstad(t_lst **alst, t_lst *new_lst)
{
	if (*alst)
	{
		new_lst->next = (*alst)->next;
		new_lst->prev = *alst;
		if (!(*alst)->prev)
		{
			(*alst)->prev = new_lst;
			new_lst->next = *alst;
			(*alst)->next = new_lst;
		}
		else
		{
			(*alst)->next->prev = new_lst;
			(*alst)->next = new_lst;
		}
	}
	*alst = new_lst;
}

void	ft_lstadd_s(t_lst **cur, char *new_lst)
{
	int num;

	if (!*cur || (!(*cur)->next))
		return ;
	while (strcmp((*cur)->content, (*cur)->next->content) < 0)
		*cur = (*cur)->next;
	if (strcmp(new_lst, (*cur)->next->content) < 0)
		return ;
	num = (*cur)->num;
	*cur = (*cur)->next;
	while (strcmp(new_lst, (*cur)->content) > 0 && num != (*cur)->num)
		*cur = (*cur)->next;
	if (strcmp(new_lst, (*cur)->content) < 0)
		*cur = (*cur)->prev;
}
