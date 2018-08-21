#include "ft_printf.h"

void	ft_unsigned_ss(unsigned long long i, t_flag *flags, char *str)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->zero && flags->precision < flags->width && flags->pre_e)
		flags->zero = 0;
	if (i == 0)
	{
		if (flags->pre_e == 1 && flags->precision == 0)
			flags->base == 16 ? flags->hash = 0 : 0;
		else
		{
			flags->o_zero = 1;
			flags->hash = 0;
			str[0] = '0';
		}
	}
	if (flags->hash == 1 && flags->pre_e == 1 && flags->precision == 0)
		return ;
	else if (flags->hash == 1)
	{
		if (flags->base == 8)
			flags->width -= 1;
		else if (flags->base == 16)
			flags->width -= 2;
	}
}

void	ft_unsigned_order(t_flag *flags, t_numbers *n, char *str, int len)
{
	if (flags->minus)
	{
		ft_un_hash(flags, n);
		ft_un_put(str, n, *flags);
		ft_d_width(n, *flags, len);
	}
	else
	{
		if (flags->zero)
		{
			ft_un_hash(flags, n);
			ft_d_width(n, *flags, len);
			ft_un_put(str, n, *flags);
		}
		else
		{
			ft_d_width(n, *flags, len);
			ft_un_hash(flags, n);
			ft_un_put(str, n, *flags);
		}
	}
}

int		ft_unsigned(va_list args, const char *format, t_numbers *n)
{
	t_flag				flags;
	int					form;
	unsigned long long	i;
	char				*str;
	int					len;

	form = 0;
	flags = ft_flags(format, 4, args, &form);
	flags.base = ft_unsigned_s(format, &flags);
	i = ft_un_cv(flags, args);
	str = ft_llitoa_base(i, flags.base, flags);
	ft_unsigned_ss(i, &flags, str);
	len = ft_strlen(str);
	ft_unsigned_order(&flags, n, str, len);
	free(str);
	return (form + 1);
}
