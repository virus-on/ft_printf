/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integerlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:31:27 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 16:02:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_llintegerlen(unsigned long long n, int base)
{
	size_t	l;

	l = 0;
	while (n)
	{
		n /= base;
		l++;
	}
	return (l);
}
