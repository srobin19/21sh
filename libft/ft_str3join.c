/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:41:18 by losuna-b          #+#    #+#             */
/*   Updated: 2019/10/05 21:41:19 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	s_cpy(char *dest, size_t *i, char const *s)
{
	int j;

	j = 0;
	while (s[j])
	{
		dest[*i] = s[j];
		(*i)++;
		j++;
	}
}

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*dest;
	size_t	i;

	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (dest == NULL)
		return (NULL);
	i = 0;
	s_cpy(dest, &i, s1);
	s_cpy(dest, &i, s2);
	s_cpy(dest, &i, s3);
	return (dest);
}
