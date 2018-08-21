/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:35:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/08 16:18:18 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_floating_g(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	long double	i;
	va_list		args2;

	form = 0;
	flags = ft_flags(format, 10, args, &form);
	(flags.pre_e == 0) ? (flags.precision = 7) : (flags.precision += 1);
	(flags.pre_e == 1 && flags.precision == 0) ? (flags.precision += 1) : 0;
	va_copy(args2, args);
	i = ft_f_cv(flags, args2);
	ft_ftoa_e_ss(&i, n);
	if (flags.precision > n->e_no && n->e_no >= -4)
		ft_floating_o(args, format, n);
	else
		ft_floating_e(args, format, n);
	va_end(args2);
	return (form + 1);
}
