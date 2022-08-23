NAME		= fdf
INCLUDES	= fdf.h
SOURCES		= main.c load_data.c scene.c draw_line.c render.c cleanup.c events.c

LIBFT		= ./libft/libft.a

SRCS_PATH	= src
OBJS_PATH	= obj
SRCS		= $(addprefix $(SRCS_PATH)/, $(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(SOURCES:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

CYAN		= \033[1;36m
RESET		= \033[0m

LOG			= printf "$(CYAN)info:$(RESET) %s\n"

all:		$(NAME)

norma:
	@norminette $(SRCS_PATH) include

$(NAME):	$(OBJS_PATH) $(LIBFT) $(OBJS) $(addprefix include/, $(INCLUDES))
	@$(LOG) "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@$(LOG) "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(LOG) "Compiling libft..."
	git submodule init
	git submodule update
	@make -C ./libft --no-print-directory

clean:
	@$(RM) -r $(OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
