#include "ft_printf.h"

void	ft_d_width(t_numbers *n, t_flag flags, int len)
{
	if (flags.precision > len)
		while (flags.width-- > flags.precision)
			n->return_i += (flags.zero == 1 ?
			write(n->fd, "0", 1) : write(n->fd, " ", 1));
	else
		while (flags.width-- > len)
			n->return_i += (flags.zero == 1 ?
			write(n->fd, "0", 1) : write(n->fd, " ", 1));
}

void	ft_d_put(char *str, int len, t_numbers *n, t_flag flags)
{
	int		i;

	i = flags.precision;
	if (flags.sign)
		n->return_i += write(n->fd, "-", 1);
	else if (flags.plus && !flags.sign)
		n->return_i += write(n->fd, "+", 1);
	else if (flags.space && !flags.sign)
		n->return_i += write(n->fd, " ", 1);
	if (flags.zero)
		ft_d_width(n, flags, len);
	while (i-- > len)
		n->return_i += write(n->fd, "0", 1);
	if (str[0] == '0' && flags.pre_e == 1 && flags.precision == 0)
		flags.width > 0 ? n->return_i += write(n->fd, " ", 1) : 0;
	else
		ft_str_put(str, len, n);
	if (flags.minus)
		ft_d_width(n, flags, len);
}

void	ft_d_precision(t_flag *flags)
{
	if ((flags->plus || flags->space) && !flags->sign)
		flags->width -= 1;
	else if (flags->sign)
		flags->width -= 1;
	if (flags->minus)
		flags->zero = 0;
	if (flags->zero && flags->precision < flags->width && flags->pre_e)
		flags->zero = 0;
}

void	ft_d_sign(int *len, char *str, t_flag *flags)
{
	if (str[0] == '-')
	{
		flags->sign = 1;
		*len -= 1;
	}
}

int		ft_decimal(va_list args, const char *format, t_numbers *n)
{
	t_flag		flags;
	int			form;
	char		*str;
	long long	i;
	int			len;

	form = 0;
	flags = ft_flags(format, 3, args, &form);
	i = ft_d_cv(flags, args);
	str = ft_itoa(i, flags);
	len = ft_strlen(str);
	ft_d_sign(&len, str, &flags);
	ft_d_precision(&flags);
	if (flags.minus || flags.zero)
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	else
	{
		ft_d_width(n, flags, len);
		flags.sign == 1 ?
		ft_d_put(str + 1, len, n, flags) : ft_d_put(str, len, n, flags);
	}
	free(str);
	return (form + 1);
}
