/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:33:58 by srobin            #+#    #+#             */
/*   Updated: 2020/02/07 16:42:57 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"

#define BUFFER_SIZE 3

int			putch(int c)
{
	write(1, &c, 1);
	return (c);
}

int			main(int argc, char **argv)
{
	char		reader[4];
	t_term_d	*data;
	char		*line;
	(void)argc;
	(void)argv;

	init_raw_mode();
	init_term_data();
	data = init_term_data();
	ft_putstr_fd("prompt > ", 0);
	while (1)
	{
		ft_bzero(reader, BUFFER_SIZE);
		read(0, reader, BUFFER_SIZE);

		if (execute_command(reader, &line))
			continue ;
		if (execute_termcap(data, reader, BUFFER_SIZE, &line))
			continue ;

		if (reader[0])
		{
			ft_putchar_fd(reader[0], 0);
			update_input(reader, &line);
		}
//		else if (reader[0])
//			ft_putstr_fd(reader, 0);
		if (reader[0] && reader[0] == '\n')
			ft_putstr_fd("prompt > ", 0);
	}



/*
		ft_putstr("\033[33m\033[01m21sh $> \033[0m");
		get_next_line(0, &input);
	if (ret == 0)
	{
		//get_terminal_id(getenv("TERM"));
		if (input && !(ft_strcmp(input, "clear")))
			tputs(clear_term, 1, putch);
	//		tputs(tgoto(cm_cap, 50, 0), 1, putch);
	}
	return (0);
}
*/

/*
int			main(void)
{
	char *line = ft_strdup("0123456789");
	char *input = "------";
	paste_input(&line, input, 12);
	ft_putendl(line);
	return (0);£
*/
}
