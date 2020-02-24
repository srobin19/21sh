/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:36:01 by srobin            #+#    #+#             */
/*   Updated: 2020/01/23 19:28:33 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"

t_term_d		*init_term_data()
{
	t_term_d	*data;

	data = malloc(sizeof(t_term_d));

	data->co_size = tgetnum("co");
	data->li_size = tgetnum("li");
	data->move_left = tgetstr("le", NULL);
	data->move_right = tgetstr("nd", NULL);
	data->line_up = tgetstr("up", NULL);
	data->line_down = tgetstr("down", NULL);
	data->clear_line = tgetstr("cd", NULL);
	data->cursor_start = tgetstr("cr", NULL);
	data->move_cursor = tgetstr("cm", NULL);
	data->co_x = 1;
	data->li_y = 1;
	return (data);
}

int				init_term()
{
	int			ret;
	char		*term_type;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_putendl_fd("TERM must be set in ENV.", 2);
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_putendl_fd("No acces to the termcap database..", 2);
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal type is not defined in termcap database..", 2);
		return (-1);
	}
	return (1);
}

void			init_raw_mode()
{
	struct		termios	term;
	int			ret;

	if (!(ret = init_term()))
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &term) == -1)
		ft_exit_failure("Couldn't get termios struct attributes..", 2);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSANOW, &term) == -1))
		ft_exit_failure("Couldn't set ICANON mode with tcsetattr..", 2);
}
