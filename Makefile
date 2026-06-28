NAME   = push_swap
CC     = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR = srcs
OBJ_DIR = objs

SRC_FILES =   main.c\
              libft_utils.c\
              stack_utils.c\
              split_fill.c\
              op_p.c\
              op_s.c\
              op_r.c\
              op_rr.c\
              parsing.c\
              sort_small.c\
              sort_utils.c\
              sort_large.c

SRCS   = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS   = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re