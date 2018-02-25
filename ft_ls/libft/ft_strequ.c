/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:43:03 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/25 18:43:07 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strcmp(s1, s2);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
