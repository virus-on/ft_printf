/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:06:19 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 15:05:47 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_llitoa_base_s(char *aba)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = '0';
	while (tmp <= '9')
		aba[i++] = tmp++;
	tmp = 'a';
	while (tmp <= 'z')
		aba[i++] = tmp++;
}

void	ft_llitoa_s(unsigned long long *n, t_flag flags)
{
	unsigned short int	a;
	unsigned char		b;

	if (flags.length == 2)
	{
		a = (unsigned short int)*n;
		*n = (unsigned long long)a;
	}
	else if (flags.length == 1)
	{
		b = (unsigned char)*n;
		*n = (unsigned long long)b;
	}
}

char	*ft_llitoa_base(unsigned long long n, int base, t_flag flags)
{
	size_t	i;
	size_t	len;
	char	*str;
	char	*aba;

	aba = ft_memalloc(37);
	ft_llitoa_s(&n, flags);
	ft_llitoa_base_s(aba);
	i = 0;
	len = ft_llintegerlen(n, base);
	str = ft_memalloc(len + 1);
	while (i < len)
	{
		str[--len] = aba[(n % base)];
		n = n / base;
	}
	free(aba);
	return (str);
}
