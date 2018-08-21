#include "ft_printf.h"
#include <inttypes.h>

long double				ft_f_cv(t_flag flags, va_list args)
{
	if (flags.length == 0)
		return (va_arg(args, double));
	else if (flags.length == 4)
		return (va_arg(args, long double));
	return (-1);
}

long long				ft_d_cv(t_flag flags, va_list args)
{
	if (flags.length == 0 || flags.length == 1 || flags.length == 2)
		return (va_arg(args, int));
	else if (flags.length == 3)
		return (va_arg(args, long));
	else if (flags.length == 4)
		return (va_arg(args, long long));
	else if (flags.length == 5)
		return (va_arg(args, intmax_t));
	else if (flags.length == 6)
		return (va_arg(args, size_t));
	return (0);
}

unsigned long long		ft_un_cv(t_flag flags, va_list args)
{
	if (flags.length == 0 || flags.length == 1 || flags.length == 2)
		return (va_arg(args, unsigned int));
	else if (flags.length == 3)
		return (va_arg(args, unsigned long));
	else if (flags.length == 4)
		return (va_arg(args, unsigned long long));
	else if (flags.length == 5)
		return (va_arg(args, intmax_t));
	else if (flags.length == 6)
		return (va_arg(args, size_t));
	return (0);
}
