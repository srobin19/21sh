/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:46:32 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:51:21 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	while (*s != '\0')
	{
		if (*s == a)
			return ((char*)(s));
		s++;
	}
	if (c == '\0')
		return ((char*)(s));
	return (NULL);
}
