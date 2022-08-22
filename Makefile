NAME	= fdf
SOURCES	= main.c load_data.c cleanup.c

LIBFT	= ./libft/libft.a

INCLUDES	= include
SRCS_PATH	= src
OBJS_PATH	= obj
SRCS	= $(addprefix $(SRCS_PATH)/, $(SOURCES))
OBJS	= $(addprefix $(OBJS_PATH)/, $(SOURCES:.c=.o))

CFLAGS	= -Wall -Wextra -Werror -g
RM			= rm -f

CYAN	= \33[1;36m
NC		= \033[0m

LOG	= printf "$(CYAN)info: $(NC)"

all:		$(NAME)

# ---------------------------------------
build: CFLAGS += -O2
build: all

debug: CFLAGS += -g
debug: all

norma:
	@ norminette $(SRCS_PATH) $(INCLUDES)

# ---------------------------------------

$(NAME):	$(OBJS_PATH) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@$(LOG)
	@echo "Compiling $@"
	$(CC) $(CFLAGS) -c $< -o $@

${LIBFT}:
	@$(LOG)
	@echo "Compiling libft..."
	@make -C ./libft --no-print-directory

clean:
	@$(RM) -r $(OBJS_PATH)

fclean: clean
	@make fclean -C ./libft --no-print-directory -s
	@$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
