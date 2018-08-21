/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:06:19 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/30 21:14:48 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_doitoa_base_s(char *aba)
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

char	*ft_doitoa_base(long double n, int base)
{
	size_t	i;
	size_t	len;
	char	*str;
	char	*aba;

	aba = ft_memalloc(37);
	ft_llitoa_base_s(aba);
	i = 0;
	len = ft_dointegerlen(n, base);
	str = ft_memalloc(len + 1);
	while (i < len)
	{
		str[--len] = aba[(n % base)];
		n = n / base;
	}
	free(aba);
	return (str);
}
