#include "txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		ft_putendl_fd(lines[i], 1);
		i++;
	}
}