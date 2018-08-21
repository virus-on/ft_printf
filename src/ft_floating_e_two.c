/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_e_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:56:24 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/08 18:00:11 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_e_put(char *str, int len, t_numbers *n, t_flag flags)
{
	int		i;

	i = flags.precision;
	if (flags.sign)
		n->return_i += write(n->fd, "-", 1);
	else if (flags.plus && !flags.sign)
		n->return_i += write(n->fd, "+", 1);
	else if (flags.space && !flags.sign)
		n->return_i += write(n->fd, " ", 1);
	if (flags.zero)
		ft_d_width(n, flags, len);
	while (i-- > len)
		n->return_i += write(n->fd, "0", 1);
	if (str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
		flags.width > 0 ? n->return_i += write(n->fd, " ", 1) : 0;
	else
		ft_str_put(str, len, n);
	if (flags.minus)
		ft_d_width(n, flags, len);
}

void	ft_e_order(t_flag flags, char *str, int len, t_numbers *n)
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

void	ft_ftoa_e_ss(long double *val, t_numbers *n)
{
	unsigned long long int	tmp;

	n->e_no = 0;
	tmp = (unsigned long long int)*val;
	if (*val == 0)
		return ;
	else if (tmp > 9)
	{
		while (tmp > 9)
		{
			*val /= 10;
			tmp = (unsigned long long int)*val;
			n->e_no += 1;
		}
	}
	else if (tmp < 1)
	{
		while (tmp < 1)
		{
			*val *= 10;
			tmp = (unsigned long long int)*val;
			n->e_no -= 1;
		}
	}
}
