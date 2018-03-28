/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:21:08 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/28 18:21:09 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lst_cpy(t_lst **src, t_lst *cpy)
{
	(*src)->content = cpy->content;
	(*src)->path = cpy->path;
	(*src)->date = cpy->date;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_uid = cpy->st_uid;
	(*src)->st_gid = cpy->st_gid;
	(*src)->st_size = cpy->st_size;
	(*src)->st_blocks = cpy->st_blocks;
}

void	ft_swap_el(t_lst **a, t_lst **b)
{
	t_lst tmp;

	tmp = **a;
	ft_lst_cpy(a, *b);
	ft_lst_cpy(b, &tmp);
}

void	ft_cheack_lst(t_lst *a)
{
	t_lst *b;

	b = a->next;
	while (b->next)
	{
		(a->date < b->date) ? ft_swap_el(&a, &b) : 0;
		((a->date == b->date) && \
		(ft_strcmp(a->content, b->content) > 0)) ? ft_swap_el(&b, &a) : 0;
		b = b->next;
	}
	if (!b->next)
	{
		(a->date < b->date) ? ft_swap_el(&a, &b) : 0;
		((a->date == b->date) && \
		(ft_strcmp(a->content, b->content) > 0)) ? ft_swap_el(&b, &a) : 0;
	}
}

void	ft_timesort(t_lst *lst_f, t_param lst_p)
{
	t_lst *a;
	t_lst *tmp;

	if (!lst_f->next && lst_p.t == 0 && lst_p.u == 0)
		return ;
	lst_f->prev->next = NULL;
	lst_f->prev = NULL;
	a = lst_f;
	while (a->next)
	{
		ft_cheack_lst(a);
		a = a->next;
	}
	tmp = a;
	while (a->prev)
		a = a->prev;
	a->prev = tmp;
	a->prev->next = a;
	while (a->date > a->next->date)
		a = a->next;
	a = a->next;
	lst_f = a;
}
