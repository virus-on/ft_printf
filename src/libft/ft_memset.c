/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:31:39 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/26 19:33:55 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int constant_byte, size_t n)
{
	size_t	i;
	void	*temp;

	i = 0;
	temp = array;
	while (i < n)
	{
		*(unsigned char*)temp = constant_byte;
		temp++;
		i++;
	}
	return (array);
}
