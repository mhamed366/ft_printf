/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_to_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:59:50 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 18:59:51 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count = 0;

int	u_to_hex(unsigned long long nbr, int round)
{
	char	to_print;

	if (round == 1)
		g_count = 0;
	if (nbr == 0)
		return (0);
	u_to_hex(nbr / 16, round + 1);
	if (nbr % 16 < 10)
	{
		to_print = nbr % 16 + '0';
		g_count += write(1, &to_print, 1);
	}
	else
	{
		to_print = nbr % 16 + 'a' - 10;
		g_count += write(1, &to_print, 1);
	}
	return (g_count);
}
