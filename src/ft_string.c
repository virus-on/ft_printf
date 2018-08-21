#include "ft_printf.h"

void	ft_str_null(t_numbers *n, t_flag flag)
{
	int len;

	len = ((flag.precision <= 0 && flag.pre_e == 0) ? 6 : flag.precision);
	while (flag.width-- > len)
		n->return_i += (flag.zero == 1 ?
		write(n->fd, "0", 1) : write(n->fd, " ", 1));
	n->return_i += write(n->fd, "(null)", len);
}

void	ft_str_put(char *str, int len, t_numbers *n)
{
	int	i;

	i = -1;
	while (++i < len)
		n->return_i += write(n->fd, &str[i], 1);
}

void	ft_str_width(t_numbers *n, t_flag flags, int len)
{
	while (flags.width-- > len)
		n->return_i += write(n->fd, " ", 1);
}

void	ft_string_s(t_numbers *n, t_flag flags, char *str, int len)
{
	if (flags.minus)
	{
		ft_str_put(str, len, n);
		ft_str_width(n, flags, len);
	}
	else
	{
		ft_str_width(n, flags, len);
		ft_str_put(str, len, n);
	}
}

int		ft_string(va_list args, const char *format, t_numbers *n)
{
	t_flag	flags;
	int		form;
	char	*str;
	int		len;

	form = 0;
	flags = ft_flags(format, 2, args, &form);
	if (flags.length == 4)
		return (ft_wide_str(args, form, flags, n));
	str = ft_strdup(va_arg(args, char*));
	if (str == NULL)
	{
		ft_str_null(n, flags);
		return (form + 1);
	}
	len = ft_strlen(str);
	if (flags.precision < len && flags.pre_e == 1)
		len = flags.precision;
	ft_string_s(n, flags, str, len);
	free(str);
	return (form + 1);
}
