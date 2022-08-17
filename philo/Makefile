# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/08/17 20:14:30 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=thread

LIBFT_FLAGS =	-L$(LIBFT_DIR) -lft
INCS_FLAGS	=	-I$(LIBFT_DIR) -I $(INCS_DIR)

LIBFT_AR	=	libft.a

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR 	=	./includes/
LIBFT_DIR	=	./libft/

SRCS_NAME	=	main.c 				

OBJS_NAME	=	$(SRCS_NAME:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))
LIBFT		=	$(LIBFT_DIR)$(LIBFT_AR)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCS_FLAGS) -c $< -o $@

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	@make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean
	make all

.PHONY: all clean fclean re debug
