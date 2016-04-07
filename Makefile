NAME=fractol
FLAGS=-O2 -Wall -Wextra -Werror -I includes/
LIBFT=libft.a
LIBFLAGS=-lft -L libft/ -lmlx -framework OpenGL -framework AppKit -lm
SRCSF=key_hooks2.c key_hooks.c display_menu.c newton.c burning_ship.c julia.c \
		palettes.c mouse_hooks.c mouse_hooks2.c mandel.c main.c cplx_tools.c
OBJSF=$(SRCSF:.c=.o)
SRCDIR=srcs/
OBJDIR=objs/
SRCS=$(addprefix srcs/, $(SRCSF))
OBJS=$(addprefix objs/, $(OBJSF))

all: $(LIBFT) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo " \c"
	@gcc $(FLAGS) -c $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "\033[1;35m$(NAME) compiling... |\033[0m\033[45m\c"

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\033[0m\033[1;35m|\033[0m"
	@mv $(OBJSF) $(OBJDIR)
	@gcc $(LIBFLAGS) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;32m$(NAME) ready ✓\033[0m"

clean:
	@rm -rf objs/
	@make -C libft clean
	@echo "\033[1;31m$(NAME) objects deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m$(NAME) binary file deleted\033[0m"
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
