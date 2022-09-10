# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/09/10 17:41:13 by jayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=thread
# CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=thread

INCS_FLAGS	=	-I $(INCS_DIR)

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR 	=	./includes/

SRCS_NAME	=	check_the_number_of_arguments.c \
				create_threads.c \
				do_routine_each_philo.c \
				free_all.c \
				free_info.c \
				ft_atol.c \
				ft_isdigit.c \
				ft_issign.c \
				ft_isspace.c \
				get_now_time.c \
				get_row_now_time.c \
				init_mutex_and_shared_data.c \
				init_philo_info.c \
				init_state_of_philo.c \
				is_die.c \
				join_thread.c \
				main.c \
				monitor_philos.c \
				put_down_a_fork.c \
				put_up_a_fork.c	\
				philo_eat.c	\
				xusleep.c	\
				init_a_mutex.c


OBJS_NAME	=	$(SRCS_NAME:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS_FLAGS) -c $< -o $@

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean
	make all

.PHONY: all clean fclean re debug
