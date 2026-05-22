#ifndef TXTFILE_H
# define TXTFILE_H

#define NULL ((void *)0)
typedef unsigned long size_t;
typedef long ssize_t;

int		open(const char *path, int flags, ...);
int		close(int fd);
ssize_t	read(int fd, void *buf, size_t count);
void	*malloc(size_t size);
void	free(void *ptr);

#ifndef O_RDONLY
# define O_RDONLY 0x0000
#endif

#include "libft.h"

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);
char	**cut_lines(char **lines, int start, int end);

#endif