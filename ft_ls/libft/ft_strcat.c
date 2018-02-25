/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:49:10 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 18:49:18 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*s;

	s = dest;
	while (*s != '\0')
		s++;
	while (*src != '\0')
		*s++ = *src++;
	*s = '\0';
	return (dest);
}
