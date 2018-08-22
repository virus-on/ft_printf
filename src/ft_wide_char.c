/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_char_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:10:05 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/11 18:06:24 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(char c, t_numbers *n)
{
	n->return_i += write(STD_OUT, &c, 1);
}

void	ft_putwc(wchar_t wc, t_numbers *n)
{
	if (wc <= 0x7F)
		ft_putwchar(wc, n);
	else if (wc <= 0x7FF)
	{
		ft_putwchar((wc >> 6) + 0xC0, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putwchar((wc >> 12) + 0xE0, n);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putwchar((wc >> 18) + 0xF0, n);
		ft_putwchar(((wc >> 12) & 0x3F) + 0x80, n);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80, n);
		ft_putwchar((wc & 0x3F) + 0x80, n);
	}
}

int		ft_wide_char(va_list args, int form, t_flag flags, t_numbers *n)
{
	wchar_t	wc;

	wc = va_arg(args, wchar_t);
	if (flags.minus)
	{
		n->return_i += write(STD_OUT, &wc, 1);
		ft_char_width(n, flags);
	}
	else
	{
		ft_char_width(n, flags);
		n->return_i += write(STD_OUT, &wc, 1);
	}
	return (form + 1);
}
