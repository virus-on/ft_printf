/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:30:37 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 00:17:33 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_t(char *s, t_numbers *n)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		n->return_i += write(n->fd, &s[i++], 1);
}

int		ft_unsigned_s(const char *format, t_flag *flags)
{
	int		i;
	int		base;

	i = 0;
	base = BASE_DEC;
	while (!(ft_strchr("oOuUxXb", format[i])))
		i++;
	if (format[i] == 'o' || format[i] == 'O')
		base = BASE_OCT;
	else if (format[i] == 'u' || format[i] == 'U')
		base = BASE_DEC;
	else if (format[i] == 'x' || format[i] == 'X')
	{
		if (format[i] == 'X')
			flags->x = 1;
		base = BASE_HEX;
	}
	else if (format[i] == 'b')
		base = BASE_BIN;
	return (base);
}

void	ft_un_write(char c, t_numbers *n, t_flag flags)
{
	char	a;

	a = c - 32;
	if (flags.x == 1 && (c >= 'a' && c <= 'z'))
		n->return_i += write(n->fd, &a, 1);
	else
		n->return_i += write(n->fd, &c, 1);
}

void	ft_un_put(char *str, t_numbers *n, t_flag flags)
{
	int		i;
	int		len;
	int		j;

	i = flags.precision;
	len = ft_strlen(str);
	while (i-- > len)
		n->return_i += write(n->fd, "0", 1);
	if (str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
		flags.width > 0 ? n->return_i += write(n->fd, " ", 1) : 0;
	else
	{
		j = 0;
		if (flags.o_zero == 0)
			while (str[j] == '0' && str[j] != '\0')
				j++;
		while (str[j])
			ft_un_write(str[j++], n, flags);
	}
}

void	ft_un_hash(t_flag *flags, t_numbers *n)
{
	if (flags->hash == 1)
	{
		if (flags->base == BASE_OCT || flags->base == BASE_HEX)
			ft_un_write('0', n, *flags);
		if (flags->base == BASE_HEX)
			ft_un_write('x', n, *flags);
	}
}
