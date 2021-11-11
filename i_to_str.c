/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:55:29 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 18:55:30 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_count3 = 0;

int	i_to_str(int nbr, int round)
{
	char	to_print;

	if (round == 1)
		g_count3 = 0;
	if (nbr == 0 && round == 1)
		return (write(1, "0", 1));
	else if (nbr == 0 && round != 1)
		return (0);
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		nbr *= -1;
		g_count3 += write(1, "-", 1);
	}
	i_to_str(nbr / 10, round + 1);
	to_print = nbr % 10 + '0';
	g_count3 += write(1, &to_print, 1);
	return (g_count3);
}
