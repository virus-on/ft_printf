#include "ft_printf.h"

int		ft_printf_send(va_list args, t_numbers *n, const char *format)
{
	if (n->spec == 0)
		return (ft_character(args, format, n));
	else if (n->spec == 1)
		return (ft_string(args, format, n));
	else if (n->spec == 2)
		return (ft_decimal(args, format, n));
	else if (n->spec == 3)
		return (ft_unsigned(args, format, n));
	else if (n->spec == 4)
		return (ft_pointer(args, format, n));
	else if (n->spec == 5)
		return (ft_percent(args, format, n));
	else if (n->spec == 6)
	{
		n->fd = va_arg(args, int);
		return (1);
	}
	return (-1);
}


int		ft_vsprintf_s(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'C')
		return (0);
	else if (format[i] == 's' || format[i] == 'S')
		return (1);
	else if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
		return (2);
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'b')
		return (3);
	else if (format[i] == 'p')
		return (4);
	else if (format[i] == '%')
		return (5);
	else if (format[i] == 'w')
		return (6);
	return (-1);
}
