/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:54 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 18:44:01 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_conversion(char **s, va_list arg)
{
	int	nbr;

	(void)**s;
	nbr = va_arg(arg, int);
	return (i_to_str(nbr, 1));
}

int	uint_conversion(char **s, va_list arg)
{
	unsigned int	nbr;

	(void)**s;
	nbr = va_arg(arg, unsigned int);
	return (ui_to_str(nbr, 1));
}

int	hex_conversion(char **s, va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	if (nbr == (unsigned long long) NULL)
		return (write(1, "0", 1));
	if (**s == 'x')
		return (to_hex(nbr, 0, 1));
	if (**s == 'X')
		return (to_hex(nbr, 1, 1));
	return (0);
}
