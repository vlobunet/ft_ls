/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:21:29 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:21:30 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new_lst)
{
	static	t_list	*head;

	if (!*alst)
		*alst = new_lst;
	else
	{
		new_lst->next = (*alst)->next;
		(*alst)->next = new_lst;
		new_lst->prev = *alst;
		if (head)
			head->prev = new_lst;
	}
	if (!head)
		head = *alst;
	*alst = new_lst;
}
