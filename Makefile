# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 16:58:58 by iseletsk          #+#    #+#              #
#    Updated: 2018/05/12 15:23:01 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./libraries/

SRC :=		main.c  wizard.c  rapid_boost.c\
			input.c input_friendly.c loop.c\
			ft_rainbow.c shapes.c\
			mandelbrot.c julia.c vessel.c arachnid.c rubber.c alien.c\
			blur.c trinity.c\

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)includes/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		-Wall -Wextra -Werror

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

CC :=		gcc

.SILENT:

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) $(LINK_FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created fractal"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned fractal"

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fully cleaned fractal"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
