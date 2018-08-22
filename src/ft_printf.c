/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:26:02 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/14 20:57:30 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 0 = int converted to unsigned char
** 1 = char *
** 2 = signed decimal
** 3 = unsigned octal (o), unsigned decimal (u),
** unsigned hexadecimal (x & X), unsigned binary (b)
** 4 = pointer
** 5 = percent
** 6 = change fd
*/

void	ft_vsprintf_ss(const char *format, t_numbers *n)
{
	if (format[n->i] != '%' && format[n->i] != '\0')
	{
		n->return_i += write(STD_OUT, &format[n->i], 1);
		n->i += 1;
	}
}

int		ft_vsprintf(const char *format, va_list args, t_numbers *n)
{
	ft_bzero(n, sizeof(t_numbers));
	while (format[n->i] != '\0')
	{
		if (format[n->i] == '%')
		{
			n->k = n->i++;
			while (!ft_strchr(FT_PREC, format[n->i]))
				n->i++;
			if (ft_strchr(FT_PREC, format[n->i]))
			{
				n->spec = ft_vsprintf_s(format, n->i);
				format += n->k;
				n->i = ft_printf_send(args, n, format);
				format += n->i;
				n->i = 0;
			}
		}
		ft_vsprintf_ss(format, n);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	t_numbers	n;

	ft_bzero(&n, sizeof(t_numbers));
	va_start(args, format);
	i = ft_vsprintf(format, args, &n);
	if (i == -1)
		return (-1);
	va_end(args);
	return (n.return_i);
}
