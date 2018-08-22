/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:03:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/14 20:06:10 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_send(va_list args, t_numbers *n, const char *format)
{
	if (n->spec == SPEC_CHAR)
		return (ft_character(args, format, n));
	else if (n->spec == SPEC_STRING)
		return (ft_string(args, format, n));
	else if (n->spec == SPEC_DEC)
		return (ft_decimal(args, format, n));
	else if (n->spec == SPEC_UNSIGNED)
		return (ft_unsigned(args, format, n));
	else if (n->spec == SPEC_POINTER)
		return (ft_pointer(args, format, n));
	else if (n->spec == SPEC_PERCENT)
		return (ft_percent(args, format, n));
	return (INVALID);
}

int		ft_vsprintf_s(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'C')
		return (SPEC_CHAR);
	else if (format[i] == 's' || format[i] == 'S')
		return (SPEC_STRING);
	else if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
		return (SPEC_DEC);
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'b')
		return (SPEC_UNSIGNED);
	else if (format[i] == 'p')
		return (SPEC_POINTER);
	else if (format[i] == '%')
		return (SPEC_PERCENT);
	return (INVALID);
}
