/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_o_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:00:26 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/08 18:03:15 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round_up(char **str)
{
	int		len;

	len = ft_strlen(str[0]);
	len--;
	(str[0][len] > '4') ? (str[0][len - 1] += 1) : 0;
	str[0][len] = '\0';
	while (str[0][--len] == ':')
	{
		str[0][len] = '0';
		str[0][len - 1] += 1;
	}
}

void	ft_del_zero_o(char *str)
{
	int		len;

	len = ft_strlen(str);
	while (str[--len] != '.' && str[len] == '0')
		str[len] = 0;
	if (str[len] == '.')
		str[len] = 0;
}

void	ft_ftoa_s(int *i, long double *val, long int *n_val, char **tmp_t)
{
	*val *= 10;
	*n_val *= 10;
	tmp_t[0][*i] = ((long int)*val - *n_val) + '0';
	*n_val = (long int)*val;
	*i += 1;
}
