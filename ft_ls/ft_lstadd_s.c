/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:03:58 by vlobunet          #+#    #+#             */
/*   Updated: 2018/03/26 19:03:58 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
