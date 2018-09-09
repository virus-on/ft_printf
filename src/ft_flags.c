#include "ft_printf.h"

t_flag		ft_flags(const char *format, int s, int *form)
{
	t_flag	flags;
	int		i;

	ft_bzero(&flags, sizeof(t_flag));
	flags.spec = s;
	*form += 1;
	i = 0;
	while (!ft_strchr(FT_PREC, format[*form]))
	{
		if ((i < 2) && (ft_strchr(ACTION_FLAGS, format[*form])))
			i = ft_flag(format[*form], &flags);
		else if ((i < 3) && ((format[*form] >= '0' && format[*form] <= '9')))
			i = ft_width(format, &flags, &form);
		else if ((i < 4) && (format[*form] == '.'))
			i = ft_precision(format, &flags, &form);
		else if ((i < 5) && (ft_strchr(LENGTH_FLGS, format[*form])))
			i = ft_length(format, &flags, &form);
		*form += 1;
	}
	if (ft_strchr("CSDOU", format[*form]))
		i = ft_length(format, &flags, &form);
	return (flags);
}
