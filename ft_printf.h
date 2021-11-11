/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:48:23 by mkchikec          #+#    #+#             */
/*   Updated: 2021/09/14 18:51:03 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	char_conversion(char **s, va_list arg);
int	process_conversion(char **s, va_list arg);
int	process(char **s,	va_list arg);
int	ft_printf(const char *s, ...);
int	string_conversion(char **s, va_list arg);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	pointer_conversion(char **s, va_list arg);
int	u_to_hex(unsigned long long nbr, int round);
int	i_to_str(int nbr, int round);
int	int_conversion(char **s, va_list arg);
int	uint_conversion(char **s, va_list arg);
int	ui_to_str(unsigned int nbr, int round);
int	to_hex(unsigned int nbr, int isMaj, int round);
int	hex_conversion(char **s, va_list arg);

#endif
