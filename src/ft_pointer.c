/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:36:12 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 15:06:25 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_put(char *str, int len, t_numbers *n)
{
	int		i;

	i = -1;
	n->return_i += write(STD_OUT, "0x", 2);
	while (++i < len)
		n->return_i += write(STD_OUT, &str[i], 1);
}

int		ft_pointer(va_list args, const char *format, t_numbers *n)
{
	int			form;
	uintmax_t	int_v;
	char		*str;
	int			len;
	t_flag		flags;

	form = 0;
	while (!ft_strchr("sSpdDioOuUxXcC", format[form]))
		form++;
	ft_bzero(&flags, sizeof(t_flag));
	int_v = (uintmax_t)va_arg(args, void*);
	str = ft_llitoa_base(int_v, BASE_HEX, flags);
	if (int_v == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	len = ft_strlen(str);
	ft_pointer_put(str, len, n);
	free(str);
	return (form + 1);
}
