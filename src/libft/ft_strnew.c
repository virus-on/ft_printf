/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:57:56 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/25 15:47:23 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	mem = (char*)malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, (int)'\0', size + 1);
	return (mem);
}
