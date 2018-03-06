/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:23:12 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:23:13 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int num, char *str)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->num = num;
	lst->content = ft_strdup(str);
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
