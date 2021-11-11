/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:03:57 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 19:03:58 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count2 = 0;

int	ui_to_str(unsigned int nbr, int round)
{
	char	to_print;

	if (round == 1)
		g_count2 = 0;
	if (nbr == 0 && round == 1)
		return (write(1, "0", 1));
	else if (nbr == 0 && round != 1)
		return (0);
	ui_to_str(nbr / 10, round + 1);
	to_print = nbr % 10 + '0';
	g_count2 += write(1, &to_print, 1);
	return (g_count2);
}
