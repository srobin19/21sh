/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:34 by srobin            #+#    #+#             */
/*   Updated: 2020/01/23 19:25:53 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"

#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define HISTORY_UP 3
#define HISTORY_DOWN 4
/*
int			check_termcap_bs(t_term_d *data, char *input)
{
	if (!input)
		return (-1);
	if (input[0] == 27 && input[1] == 91 && input[2] == 68)
	{
		tputs(data->backspace, 0, putch);
		ft_putchar_fd(' ', 0);
		tputs(data->backspace, 0, putch);
		return (1);
	}
	return (0);
}
*/
int			check_termcap_key(char *input, size_t buffer)
{
	size_t	max_size;
	
	if (!input)
		return (-1);
	max_size = ft_strlen(input);
	if (max_size != buffer)
		return (0);
	if (input[0] == 27 && input[1] == 91 && input[2] == 68)
		return (MOVE_LEFT);
	if (input[0] == 27 && input[1] == 91 && input[2] == 67)
		return (MOVE_RIGHT);
	if (input[0] == 27 && input[1] == 91 && input[2] == 65)
		return (HISTORY_UP);
	if (input[0] == 27 && input[1] == 91 && input[2] == 66)
		return (HISTORY_DOWN);
	return (0);
}

int			execute_termcap(t_term_d *data, char *input, size_t buffer)
{
	if (!input)
		return (-1);
	if (!check_termcap_key(input, buffer))
		return (0);
	if (check_termcap_key(input, buffer) == MOVE_LEFT)
		tputs(data->move_left, 0, putch);
	else if (check_termcap_key(input, buffer) == MOVE_RIGHT)
		tputs(data->move_right, 0, putch);
	else if (check_termcap_key(input, buffer) == HISTORY_UP)
		ft_putstr_fd("HISTORY_UP", 0);
	else if (check_termcap_key(input, buffer) == HISTORY_DOWN)
		ft_putstr_fd("HISTORY_DOWN", 0);
	return (1);
}
