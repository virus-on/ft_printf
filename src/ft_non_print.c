/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_non_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:45:18 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/02 18:30:38 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_non_print_three(char c, t_numbers *n)
{
	if (c == 22)
		n->return_i += write(n->fd, "[SYN]", 5);
	else if (c == 23)
		n->return_i += write(n->fd, "[ETB]", 5);
	else if (c == 24)
		n->return_i += write(n->fd, "[CAN]", 5);
	else if (c == 25)
		n->return_i += write(n->fd, "[EM]", 4);
	else if (c == 26)
		n->return_i += write(n->fd, "[SUB]", 5);
	else if (c == 27)
		n->return_i += write(n->fd, "[ESC]", 5);
	else if (c == 28)
		n->return_i += write(n->fd, "[FS]", 4);
	else if (c == 29)
		n->return_i += write(n->fd, "[GS]", 5);
	else if (c == 30)
		n->return_i += write(n->fd, "[RS]", 5);
	else if (c == 31)
		n->return_i += write(n->fd, "[US]", 5);
	else
		n->return_i += write(n->fd, &c, 1);
}

void	ft_non_print_two(char c, t_numbers *n)
{
	if (c == 11)
		n->return_i += write(n->fd, "[VT]", 4);
	else if (c == 12)
		n->return_i += write(n->fd, "[FF]", 4);
	else if (c == 13)
		n->return_i += write(n->fd, "[CR]", 4);
	else if (c == 14)
		n->return_i += write(n->fd, "[SO]", 4);
	else if (c == 15)
		n->return_i += write(n->fd, "[SI]", 4);
	else if (c == 16)
		n->return_i += write(n->fd, "[DLE]", 5);
	else if (c == 17)
		n->return_i += write(n->fd, "[DC1]", 5);
	else if (c == 18)
		n->return_i += write(n->fd, "[DC2]", 5);
	else if (c == 19)
		n->return_i += write(n->fd, "[DC3]", 5);
	else if (c == 20)
		n->return_i += write(n->fd, "[DC4]", 5);
	else if (c == 21)
		n->return_i += write(n->fd, "[NAK]", 5);
	else
		ft_non_print_three(c, n);
}

void	ft_non_print_one(char c, t_numbers *n)
{
	if (c == 0)
		n->return_i += write(n->fd, "[NUL]", 5);
	else if (c == 1)
		n->return_i += write(n->fd, "[SOH]", 5);
	else if (c == 2)
		n->return_i += write(n->fd, "[STX]", 5);
	else if (c == 3)
		n->return_i += write(n->fd, "[ETX]", 5);
	else if (c == 4)
		n->return_i += write(n->fd, "[EOT]", 5);
	else if (c == 5)
		n->return_i += write(n->fd, "[ENQ]", 5);
	else if (c == 6)
		n->return_i += write(n->fd, "[ACK]", 5);
	else if (c == 7)
		n->return_i += write(n->fd, "[BEL]", 5);
	else if (c == 8)
		n->return_i += write(n->fd, "[BS]", 4);
	else if (c == 9)
		n->return_i += write(n->fd, "[TAB]", 5);
	else if (c == 10)
		n->return_i += write(n->fd, "[LF]", 4);
	else
		ft_non_print_two(c, n);
}

int		ft_non_print(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	char	*str;
	int		i;

	form = 0;
	i = -1;
	flags = ft_flags(format, 2, args, &form);
	str = ft_strdup(va_arg(args, char*));
	while (str[++i])
		ft_non_print_one(str[i], n);
	if (str[i] == '\0')
		n->return_i += write(n->fd, "[NUL]", 5);
	free(str);
	return (form + 1);
}
