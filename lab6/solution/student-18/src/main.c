#include "txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;
	int		start;
	int		end;

	if (argc != 4)
	{
		ft_putendl_fd("Usage: ./cut_file <filename> <start> <end>", 2);
		return (1);
	}
	
	// Проверка, что start и end числа
	start = ft_atoi(argv[2]);
	end = ft_atoi(argv[3]);
	
	if (start <= 0 || end < start)
	{
		ft_putendl_fd("Error: Invalid range. Start must be >= 1 and end >= start", 2);
		return (1);
	}
	
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: Could not read file", 2);
		return (1);
	}
	
	result = cut_lines(lines, start, end);
	if (!result)
	{
		ft_putendl_fd("Error: cut operation failed (invalid range)", 2);
		free_lines(lines);
		return (1);
	}
	
	print_lines(result);
	
	free_lines(lines);
	free_lines(result);
	return (0);
}