#include "ft_printf.h"

int		ft_n_save(va_list args, const char *format, t_numbers *n)
{
	int		*i;
	int		form;

	form = 0;
	ft_flags(format, 7, args, &form);
	i = va_arg(args, int*);
	i[0] = n->return_i;
	return (form + 1);
}
