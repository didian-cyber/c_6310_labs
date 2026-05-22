NAME = cut_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc -I./libft/inc

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/read_file.c \
       $(SRC_DIR)/free_lines.c \
       $(SRC_DIR)/print_lines.c \
       $(SRC_DIR)/cut_lines.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re