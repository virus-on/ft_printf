/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:55:15 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/04 22:55:21 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dest);
	while (i < n && src[i] != '\0')
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
