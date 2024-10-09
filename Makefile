# Variáveis
SRCS = src/algorithms/sort_three.c	src/algorithms/sort_five.c	\
       src/moves/push.c src/moves/reverse.c src/moves/rotate.c src/moves/swap.c \
       src/errors/errors.c src/utils/utils.c src/stacks/init_stacks.c \
       src/main/main.c\
	   
NAME = push_swap
COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I -g
CC = cc

# Pasta para os arquivos objetos
OBJ_DIR = obj

# Lista de arquivos objetos
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTFDIR = ./includes/libft/ft_printf
FT_PRINT = $(FT_PRINTFDIR)/libftprintf.a

# Regras
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINT)
	@echo $(NAME) ready!

# Regra para compilar arquivos .c para .o na pasta obj
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/algorithms
	@mkdir -p $(OBJ_DIR)/moves
	@mkdir -p $(OBJ_DIR)/errors
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/stacks
	@mkdir -p $(OBJ_DIR)/main

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINT):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
