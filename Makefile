NAME     = fdf
INCLUDES = fdf.h keycode.h
INC_PATH = $(addprefix include/, $(INCLUDES))
SOURCES  = main.c load_data.c scene.c draw_line.c draw_utils.c events.c
SOURCES  += data_convert.c scene_utils.c transform.c rotation.c controls.c

LIBFT = ./libft/libft.a
MLX   = ./mlx_linux/libmlx_Linux.a

SRCS_PATH	= src
OBJS_PATH	= obj
SRCS		= $(addprefix $(SRCS_PATH)/, $(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(SOURCES:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -O3 -g
RM			= rm -f

CYAN		= \033[1;36m
RESET		= \033[0m

LOG			= printf "$(CYAN)info:$(RESET) %s\n"

all:		$(NAME)

bonus: all

norma:
	@norminette $(SRCS_PATH) include

$(NAME):	$(OBJS_PATH) $(LIBFT) $(MLX) $(OBJS) $(INC_PATH)
	@$(LOG) "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@$(LOG) "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(LOG) "Compiling libft..."
	@make -C libft --no-print-directory

$(MLX):
	@make -C mlx_linux

clean:
	@$(RM) -r $(OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
