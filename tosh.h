/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:31:33 by srobin            #+#    #+#             */
/*   Updated: 2020/01/22 19:26:53 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOSH_H
# include "./libft/libft.h"
# include <term.h>
# include <termios.h>
# include <stdlib.h>

typedef struct		s_term_d
{
	int				co_size;
	int				li_size;
	char			*move_left;
	char			*move_right;
	char			*line_up;
	char			*line_down;
}					t_term_d;
/*
**					termcaps_init.c
*/
t_term_d			*init_term_data();
int					init_term();
void				init_raw_mode();
/*
**					tgetnum.c
*/
void				get_terminal_id(const char *name);
#endif
