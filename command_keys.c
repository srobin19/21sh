/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_keys.c                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:17:34 by srobin            #+#    #+#             */
/*   Updated: 2020/02/07 15:31:41 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tosh.h"

#define ENTER 1

int     check_command_key(char *input)
{
  if (!input)
    return (-1);
  if (input[0] == '\n')
    return (ENTER);
  return (0);
}

int     execute_command(char *input, char **line)
{
  if (!input)
    return (-1);
  if (!check_command_key(input))
    return (0);
  if (check_command_key(input) == ENTER)
  {
    ft_putchar_fd('\n', 1);  
    ft_putstr_fd("prompt > ", 1);
  }
  return (1);
}
