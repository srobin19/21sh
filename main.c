/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:58 by srobin            #+#    #+#             */
/*   Updated: 2020/01/22 19:27:52 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"

int			putch(int c)
{
	write(1, &c, 1);
	return (c);
}	

int			main(int argc, char **argv)
{
	char		reader[4];
	t_term_d	*data;
	(void)argc;
	(void)argv;

	init_raw_mode();
	init_term_data();
	data = init_term_data();

	ft_putnbr(data->co_size);
	ft_putchar('\n');
	ft_putnbr(data->co_size);
	ft_putchar('\n');
	while (1)
	{
		ft_bzero(reader, 3);
		read(0, reader, 3);
		if (ft_isascii(reader[0]))
		{
			if (reader[0])
				ft_putstr_fd(reader, 0);
		}
	}
/*		ft_putstr("\033[33m\033[01m21sh $> \033[0m");
		get_next_line(0, &input);
	if (ret == 0)
	{
		//get_terminal_id(getenv("TERM"));
		if (input && !(ft_strcmp(input, "clear")))
			tputs(clear_term, 1, putch);	
	//		tputs(tgoto(cm_cap, 50, 0), 1, putch);
	}
*/	return (0);
}