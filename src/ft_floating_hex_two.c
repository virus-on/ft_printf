/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_hex_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:06:13 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 13:47:46 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_prec(t_flag *flags, double val, char **str, char type)
{
	unsigned long	cmp;
	long			num;
	int				len;
	int				cnt;
	int				i;

	len = ((flags->precision == 0 && flags->pre_e == 0) ?
			13 : flags->precision);
	*str = ft_strnew(len);
	cmp = 0x0008000000000000;
	i = -1;
	num = *(long*)&val;
	while (++i < len)
	{
		cnt = 0;
		cnt += (num & cmp) == 0 ? 0 : 8;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 4;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 2;
		cmp >>= 1;
		cnt += (num & cmp) == 0 ? 0 : 1;
		cmp >>= 1;
		str[0][i] = (cnt < 10 ? cnt + 48 : cnt + type - 10);
	}
}

void	get_a_expo(double val, char type, char **str_t, t_flag flags)
{
	char	*tmp;
	char	pre[3];
	int		i;

	i = 0;
	pre[2] = '\0';
	val < 0 ? val *= -1 : 0;
	pre[1] = ((val >= 1 || val == 0) ? '+' : '-');
	pre[0] = type + 15;
	while ((val >= 2 || val < 1) && val != 0)
	{
		if (val < 1)
			val *= 2;
		else
			val /= 2;
		++i;
	}
	tmp = ft_itoa(i, flags);
	*str_t = ft_strjoin(pre, tmp);
	free(tmp);
}
