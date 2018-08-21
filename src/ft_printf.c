#include "ft_printf.h"

/*
** 0 = int converted to unsigned char
** 1 = char *
** 2 = signed decimal
** 3 = unsigned octal (o), unsigned decimal (u),
** unsigned hexadecimal (x & X), unsigned binary (b)
** 4 = pointer
** 5 = percent
** 6 = change fd
*/

int		ft_vsprintf(const char *format, va_list args, t_numbers *n)
{
	ft_bzero(n, sizeof(t_numbers));
	n->fd = 1;
	while (format[n->i] != '\0')
	{
		if (format[n->i] == '%')
		{
			n->k = n->i++;
			while (!ft_strchr(FT_PREC, format[n->i]))
				n->i++;
			if (ft_strchr(FT_PREC, format[n->i]))
			{
				n->spec = ft_vsprintf_s(format, n->i);
				format += n->k;
				n->i = ft_printf_send(args, n, format);
				format += n->i;
				n->i = 0;
			}
		}
		else
		{
			n->return_i += write(n->fd, &format[n->i], 1);
			n->i += 1;
		}	
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	t_numbers	n;

	ft_bzero(&n, sizeof(t_numbers));
	va_start(args, format);
	i = ft_vsprintf(format, args, &n);
	if (i == -1)
		return (-1);
	va_end(args);
	return (n.return_i);
}
