/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:34:43 by srobin            #+#    #+#             */
/*   Updated: 2020/02/07 16:42:46 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"



int			update_input(char *input, char **line)
{
	char	*tmp;

	if (!input || !ft_isprint(*input))
		return (0);
	if (!*line)
	{
		if (!(*line = ft_strdup(input)))
			exit(EXIT_FAILURE);
		return (1);
	}
	if (!(tmp = ft_strjoin(*line, input)))
		exit(EXIT_FAILURE);
	free(*line);
	*line = tmp;
	return (1);
}

void		cut_input(char **line, int start, int end)
{
	char	*s1;
	char	*s2;

	if (!*line || (end < start))
		return ;
	if (!(s1 = ft_strsub(*line, 0, start)))
		exit(EXIT_FAILURE);
	if (!(s2 = ft_strsub(*line, end + 1, ft_strlen(*line))))
		exit(EXIT_FAILURE);
	free(*line);
	if (!(*line = ft_strjoin(s1, s2)))
		exit(EXIT_FAILURE);
	free(s1);
	free(s2);
}

void		paste_input(char **line, char *input, int start)
{
	char 	*s1;
	char	*s2;

	if (!*line || !input || (start > ft_strlen(*line)))
		return ;
	if (!(s1 = ft_strsub(*line, 0, start)))
		exit(EXIT_FAILURE);
	if (!(s2 = ft_strsub(*line, start, ft_strlen(*line))))
		exit(EXIT_FAILURE);
	free(*line);
	if (!(*line = ft_str3join(s1, input, s2)))
		exit(EXIT_FAILURE);
	free(s1);
	free(s2);
}
