#include "txtfile.h"

static int	count_lines_in_array(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

char	**cut_lines(char **lines, int start, int end)
{
	char	**result;
	int		total_lines;
	int		i;
	int		j;

	if (!lines)
		return (NULL);
	
	total_lines = count_lines_in_array(lines);
	
	// Проверка корректности диапазона
	if (start <= 0 || end < start || start > total_lines)
		return (NULL);
	
	// Корректировка end, если выходит за границы
	if (end > total_lines)
		end = total_lines;
	
	// Выделяем память под результат
	result = (char **)malloc(sizeof(char *) * (end - start + 2));
	if (!result)
		return (NULL);
	
	// Копируем строки с start по end (включительно) 
	j = 0;
	i = start - 1;  // потому что в массиве индексы с 0, а строки с 1
	while (i <= end - 1)  // чтобы включить последнюю строку
	{
		result[j] = ft_strdup(lines[i]);
		if (!result[j])
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return (NULL);
		}
		j++;
		i++;
	}
	result[j] = NULL;
	return (result);
}