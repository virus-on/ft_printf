/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:21:27 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 13:48:39 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_zero(char *tmp)
{
	int		i;

	i = ft_strlen(tmp);
	while (--i >= 0 && tmp[i] == '0')
		tmp[i] = '\0';
}

char	*ft_ftoa_hex(double val, t_flag *flags, char type)
{
	char	*tmp;
	char	*str_t;
	char	*str;
	char	*r_str;

	val == 0 ? str = ft_strdup("0") : hex_prec(flags, val, &str, type);
	val == 0 ? 0 : delete_zero(str);
	get_a_expo(val, type, &str_t, *flags);
	if (str[0] == '\0')
		r_str = (val == 0 ? ft_strjoin("0", str_t) : ft_strjoin("1", str_t));
	else
	{
		tmp = (val == 0 ? ft_strdup(str) : ft_strjoin("1.", str));
		r_str = ft_strjoin(tmp, str_t);
		free(tmp);
	}
	free(str);
	free(str_t);
	if (val < 0)
	{
		flags->plus = 0;
		flags->space = 0;
		--flags->width;
	}
	return (r_str);
}

char	*ft_f_weight(char *str, char type)
{
	char	*tmp;

	tmp = str;
	str = (type == 'a' ? ft_strjoin("0x", tmp) : ft_strjoin("0X", tmp));
	free(tmp);
	return (str);
}

int		ft_floating_hex(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	double		i;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	i = va_arg(args, double);
	str = ft_ftoa_hex(i, &flags, format[form]);
	str = ft_f_weight(str, format[form]);
	len = ft_strlen(str);
	if (flags.minus)
	{
		i < 0 ? n->return_i += write(n->fd, "-", 1) : 0;
		ft_d_put(str, len, n, flags);
	}
	else
	{
		ft_f_width(n, flags, len);
		i < 0 ? n->return_i += write(1, "-", 1) : 0;
		ft_d_put(str, len, n, flags);
	}
	free(str);
	return (form + 1);
}
