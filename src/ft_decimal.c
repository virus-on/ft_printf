/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:28:59 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 16:41:54 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_width(t_numbers *n, t_flag flags, int len)
{
	if (flags.precision > len)
		while (flags.width-- > flags.precision)
			n->return_i += (flags.zero == UP ?
			write(STD_OUT, "0", 1) : write(STD_OUT, " ", 1));
	else
		while (flags.width-- > len)
			n->return_i += (flags.zero == UP ?
			write(STD_OUT, "0", 1) : write(STD_OUT, " ", 1));
}

void	ft_d_put(char *str, int len, t_numbers *n, t_flag flags)
{
	int		i;

	i = flags.precision;
	if (flags.sign)
		n->return_i += write(STD_OUT, "-", 1);
	else if (flags.plus && !flags.sign)
		n->return_i += write(STD_OUT, "+", 1);
	else if (flags.space && !flags.sign)
		n->return_i += write(STD_OUT, " ", 1);
	if (flags.zero)
		ft_d_width(n, flags, len);
	while (i-- > len)
		n->return_i += write(STD_OUT, "0", 1);
	if (str[0] == '0' && flags.pre_e == UP && flags.precision == DOWN)
		flags.width > 0 ? n->return_i += write(STD_OUT, " ", 1) : 0;
	else
		ft_str_put(str, len, n);
	if (flags.minus)
		ft_d_width(n, flags, len);
}

void	ft_d_precision(t_flag *flags)
{
	if ((flags->plus || flags->space) && !flags->sign)
		flags->width -= 1;
	else if (flags->sign)
		flags->width -= 1;
	if (flags->minus)
		flags->zero = DOWN;
	if (flags->zero && flags->precision < flags->width && flags->pre_e)
		flags->zero = DOWN;
}

void	ft_d_sign(int *len, char *str, t_flag *flags)
{
	if (str[0] == '-')
	{
		flags->sign = UP;
		*len -= 1;
	}
}

int		ft_decimal(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	long long	i;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, &form);
	i = ft_d_cv(flags, args);
	str = ft_itoa(i, flags);
	len = ft_strlen(str);
	ft_d_sign(&len, str, &flags);
	ft_d_precision(&flags);
	if (flags.minus || flags.zero)
		flags.sign == UP ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	else
	{
		ft_d_width(n, flags, len);
		flags.sign == UP ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	}
	free(str);
	return (form + 1);
}
