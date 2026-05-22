#include "txtfile.h"

static int	count_lines_in_file(int fd)
{
	char	buffer[4096];
	int		bytes_read;
	int		line_count;
	int		i;

	line_count = 1;
	while (1)
	{
		bytes_read = read(fd, buffer, 4096);
		if (bytes_read <= 0)
			break ;
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				line_count++;
			i++;
		}
	}
	return (line_count);
}

static char	*read_entire_file(int fd)
{
	char	*buffer;
	char	*temp;
	char	chunk[4096];
	int		bytes_read;

	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, chunk, 4096);
		if (bytes_read <= 0)
			break ;
		chunk[bytes_read] = '\0';
		temp = ft_strjoin(buffer, chunk);
		free(buffer);
		if (!temp)
			return (NULL);
		buffer = temp;
	}
	return (buffer);
}

static char	**split_by_lines(char *content, int line_count)
{
	char	**lines;
	int		i;
	int		start;
	int		end;

	lines = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		return (NULL);
	i = 0;
	start = 0;
	while (i < line_count)
	{
		end = start;
		while (content[end] && content[end] != '\n')
			end++;
		lines[i] = ft_substr(content, start, end - start);
		if (!lines[i])
		{
			while (i > 0)
				free(lines[--i]);
			free(lines);
			return (NULL);
		}
		start = end + 1;
		i++;
	}
	lines[line_count] = NULL;
	return (lines);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	*content;
	int		line_count;
	char	**lines;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_lines_in_file(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_entire_file(fd);
	close(fd);
	if (!content)
		return (NULL);
	lines = split_by_lines(content, line_count);
	free(content);
	return (lines);
}