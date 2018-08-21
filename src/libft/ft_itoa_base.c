/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:46:00 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/26 19:32:03 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long n, int base)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (n == -2147483648)
	{
		if (base == 8)
			return (ft_strdup("-20000000000"));
		else if (base == 16)
			return (ft_strdup("-80000000"));
	}
	len = ft_integerlen(n);
	str = ft_memalloc(len + 1);
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (i < len)
	{
		str[--len] = (n % base) + '0';
		n = n / base;
	}
	return (str);
}
