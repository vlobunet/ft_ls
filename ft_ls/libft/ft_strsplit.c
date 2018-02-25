/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:40:02 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/30 11:40:07 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getword(char const *str, char sumb, size_t *point)
{
	size_t	i;

	while (str[*point] == sumb)
		*point = *point + 1;
	i = *point;
	while (str[*point])
	{
		if (str[*point] == sumb)
			break ;
		*point = *point + 1;
	}
	return (ft_strsub(str, i, *point - i));
}

char		**ft_strsplit(char const *s, char c)
{
	int		col;
	char	**str;
	int		i;
	size_t	point;

	i = 0;
	point = 0;
	if (s == NULL)
		return (NULL);
	col = ft_colword(s, c);
	str = (char**)malloc(sizeof(char*) * (col + 1));
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		str[i] = getword(s, c, &point);
	else
		while (col--)
			str[i++] = getword(s, c, &point);
	str[i] = NULL;
	return (str);
}
