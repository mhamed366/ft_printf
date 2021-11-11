/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:46:03 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 18:48:05 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_conversion(char **s, va_list arg)
{
	(*s)++;
	if (**s == 'c')
		return (char_conversion(s, arg));
	if (**s == 's')
		return (string_conversion(s, arg));
	if (**s == 'p')
		return (pointer_conversion(s, arg));
	if (**s == 'i' || **s == 'd')
		return (int_conversion(s, arg));
	if (**s == 'u')
		return (uint_conversion(s, arg));
	if (**s == 'x' || **s == 'X')
		return (hex_conversion(s, arg));
	if (**s == '%')
		return (write(1, "%", 1));
	return (0);
}

int	process(char **s,	va_list arg)
{
	if (**s == '%')
		return (process_conversion(s, arg));
	else
		return (write(1, *s, 1));
}

int	ft_printf(const char *s, ...)
{
	char	*string;
	va_list	arg;
	int		length;

	va_start(arg, s);
	string = (char *)s;
	length = 0;
	while (*string)
	{
		length += process(&string, arg);
		string++;
	}
	return (length);
}
