/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:58:29 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 19:16:49 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count4 = 0;

int	to_hex(unsigned int nbr, int isMaj, int round)
{
	char	to_print;

	if (round == 1)
		g_count4 = 0;
	if (nbr == 0)
		return (0);
	to_hex(nbr / 16, isMaj, round + 1);
	if (nbr % 16 < 10)
	{
		to_print = nbr % 16 + '0';
		g_count4 += write(1, &to_print, 1);
	}
	else
	{
		if (isMaj)
			to_print = nbr % 16 + 'A' - 10;
		else
			to_print = nbr % 16 + 'a' - 10;
		g_count4 += write(1, &to_print, 1);
	}
	return (g_count4);
}
