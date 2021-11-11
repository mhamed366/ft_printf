/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:19 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/27 14:24:20 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_conversion(char **s, va_list arg)
{
	char	single_char;

	(void)**s;
	single_char = va_arg(arg, int);
	return (write(1, &single_char, 1));
}

int	string_conversion(char **s, va_list arg)
{
	char	*str;
	int		count;

	(void)**s;
	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	pointer_conversion(char **s, va_list arg)
{
	unsigned long long	pointer;
	char				*str;
	int					count;

	(void)**s;
	count = 0;
	pointer = va_arg(arg, unsigned long long);
	if (pointer == (unsigned long long) NULL)
	{
		str = "0x0";
		while (*str)
			count += write(1, str++, 1);
		return (count);
	}
	write(1, "0x", 2);
	return (u_to_hex(pointer, 1) + 2);
}
