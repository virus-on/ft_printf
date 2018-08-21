/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:39:55 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 14:06:42 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(long double val, t_flag *flags)
{
	long int	n_val;
	int			i;
	char		*tmp_t;
	char		*tmp;
	char		*str;

	i = 0;
	val < 0 ? (flags->sign = 1) : 0;
	val < 0 ? (val *= -1) : 0;
	n_val = (long int)val;
	tmp = ft_itoa((flags->sign == 1 ? (n_val * -1) : n_val), *flags);
	tmp_t = ft_memalloc(256);
	(flags->precision == 0) ? 0 : (tmp_t[i++] = '.');
	while (flags->precision--)
		ft_ftoa_s(&i, &val, &n_val, &tmp_t);
	tmp_t[i] = 0;
	str = ft_strjoin(tmp, tmp_t);
	ft_round_up(&str);
	(flags->spec == 10) ? ft_del_zero_o(str) : 0;
	free(tmp);
	free(tmp_t);
	return (str);
}

void	ft_f_width(t_numbers *n, t_flag flags, int len)
{
	while (flags.width-- > len)
		n->return_i += (flags.zero == 1 ?
		write(n->fd, "0", 1) : write(n->fd, " ", 1));
}

void	ft_floating_o_order(t_flag flags, char *str, int len, t_numbers *n)
{
	if (flags.minus || flags.zero)
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	else
	{
		ft_f_width(n, flags, len);
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	}
}

int		ft_floating_o(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	int			len;
	long double	i;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	(format[form] == 'g' || format[form] == 'G') ? flags.spec = 10 : 0;
	(flags.pre_e == 0) ? (flags.precision = 7) : (flags.precision += 1);
	(flags.spec == 10) ? (flags.precision = flags.precision - 1 - n->e_no) : 0;
	i = ft_f_cv(flags, args);
	str = ft_ftoa(i, &flags);
	len = (flags.sign == 1 ? (ft_strlen(str) - 1) : ft_strlen(str));
	ft_d_precision(&flags);
	ft_floating_o_order(flags, str, len, n);
	free(str);
	return (form + 1);
}
