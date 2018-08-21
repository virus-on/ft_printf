#include "ft_printf.h"

void	ft_color_two(char *str, t_numbers *n, int *x)
{
	if (!ft_strncmp("{PUR}", str, 5))
		*x = write(n->fd, "\x1b[35m", 6);
	else if (!ft_strncmp("{YBL}", str, 5))
		*x = write(n->fd, "\x1b[36m", 6);
	else if (!ft_strncmp("{WHT}", str, 5))
		*x = write(n->fd, "\x1b[37m", 6);
	else if (!ft_strncmp("{BBL}", str, 5))
		*x = write(n->fd, "\x1b[40m", 6);
	else if (!ft_strncmp("{BRD}", str, 5))
		*x = write(n->fd, "\x1b[41m", 6);
	else if (!ft_strncmp("{BGR}", str, 5))
		*x = write(n->fd, "\x1b[42m", 6);
	else if (!ft_strncmp("{BYL}", str, 5))
		*x = write(n->fd, "\x1b[43m", 6);
	else if (!ft_strncmp("{BBU}", str, 5))
		*x = write(n->fd, "\x1b[44m", 6);
	else if (!ft_strncmp("{BPU}", str, 5))
		*x = write(n->fd, "\x1b[45m", 6);
	else if (!ft_strncmp("{BYW}", str, 5))
		*x = write(n->fd, "\x1b[46m", 6);
	else if (!ft_strncmp("{BWH}", str, 5))
		*x = write(n->fd, "\x1b[47m", 6);
	else if (!ft_strncmp("{END}", str, 5))
		*x = write(n->fd, "\x1b[0m", 5);
}

void	ft_color_one(char *str, t_numbers *n, int *x)
{
	if (!ft_strncmp("{BLD}", str, 5))
		*x = write(n->fd, "\x1b[1m", 5);
	else if (!ft_strncmp("{DIM}", str, 5))
		*x = write(n->fd, "\x1b[2m", 5);
	else if (!ft_strncmp("{ITA}", str, 5))
		*x = write(n->fd, "\x1b[3m", 5);
	else if (!ft_strncmp("{UND}", str, 5))
		*x = write(n->fd, "\x1b[4m", 5);
	else if (!ft_strncmp("{BLI}", str, 5))
		*x = write(n->fd, "\x1b[5m", 5);
	else if (!ft_strncmp("{HIG}", str, 5))
		*x = write(n->fd, "\x1b[7m", 5);
	else if (!ft_strncmp("{BLK}", str, 5))
		*x = write(n->fd, "\x1b[30m", 6);
	else if (!ft_strncmp("{RED}", str, 5))
		*x = write(n->fd, "\x1b[31m", 6);
	else if (!ft_strncmp("{GRN}", str, 5))
		*x = write(n->fd, "\x1b[32m", 6);
	else if (!ft_strncmp("{YEL}", str, 5))
		*x = write(n->fd, "\x1b[33m", 6);
	else if (!ft_strncmp("{BLU}", str, 5))
		*x = write(n->fd, "\x1b[34m", 6);
	else
		ft_color_two(str, n, x);
}

void	ft_color(const char *format, t_numbers *n, int *x)
{
	char	*str;
	int		i;

	i = -1;
	*x = 0;
	str = ft_memalloc(sizeof(char) * 6);
	while (++i < 5)
		str[i] = format[i];
	str[i] = '\0';
	ft_color_one(str, n, x);
	free(str);
}
