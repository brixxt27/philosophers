/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:18:01 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

# define STR_FORK	"has taken a fork"
# define STR_EAT	"is eating"
# define STR_SLEEP	"is sleeping"
# define STR_THINK	"is thinking"
# define STR_DIE	"died"

typedef struct timeval	t_timeval;

typedef enum e_bool
{
	SUCCESS,
	FAIL
}	t_bool;

typedef enum e_philo_dead
{
	ALIVE,
	DEAD
}	t_philo_dead;

typedef struct s_shared_data
{
	pthread_mutex_t	m_flag;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_seat;
	t_philo_dead	flag_dead;
	ssize_t			num_enough_eating;
	int				num_seat;
}	t_shared_data;

typedef struct s_state_of_philo
{
	ssize_t			num_philo;
	ssize_t			time_to_die;
	ssize_t			time_to_eat;
	ssize_t			time_to_sleep;
	ssize_t			num_must_eat;
}	t_state_of_philo;

typedef struct s_philo_info
{
	pthread_t			tid;
	t_state_of_philo	*state;
	t_shared_data		*sharing;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	ssize_t				time_to_start;
	ssize_t				time_to_last_eat;
	ssize_t				num_eat;
	int					idx;
}	t_philo_info;

/* check exeception and init variable */
t_bool			init_state_of_philo(t_state_of_philo *state, int argc,
					char *argv[]);
t_bool			init_mutex_and_shared_data(t_state_of_philo *state,
					t_shared_data *sharing);
t_bool			init_a_mutex(pthread_mutex_t *mutex);
t_philo_info	*init_philo_info(t_state_of_philo *state,
					t_shared_data *sharing);
void			init_time_to_start_per_philos(t_philo_info *info,
					ssize_t time_to_start);

/* about thread */
t_bool			create_threads(t_philo_info *info);
void			join_thread(t_philo_info *info, int num_of_success_thread);

/* about time */
ssize_t			get_row_now_time(void);
ssize_t			get_now_time(t_philo_info *info);
int				is_die(t_philo_info *info);
void			xusleep(t_philo_info *info, ssize_t state_time);

/* print */
void			print_status(t_philo_info *info, char *status);

/* check status */
int				is_eat_enough(t_philo_info *info);
int				check_flag_die(t_philo_info *info);

/* main: philo */
void			*do_routine_each_philo(void *fptr);
t_bool			put_up_a_fork(t_philo_info *info);
t_bool			philo_eat(t_philo_info *info);
t_bool			put_down_a_fork(t_philo_info *info);
t_bool			philo_sleep(t_philo_info *info);
t_bool			philo_think(t_philo_info *info);

/* main: monitor */
void			monitor_philos(t_philo_info *info);

#endif
