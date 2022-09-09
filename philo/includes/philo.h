/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/09 22:43:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

typedef struct timeval t_timeval;

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
	int					idx;
}	t_philo_info;

/* check exeception and init variable */
t_bool			check_the_number_of_arguments(int argc);
t_bool			init_state_of_philo(t_state_of_philo *state, int argc, \
					char *argv[]);
t_bool			init_mutex_and_shared_data(t_state_of_philo *state, t_shared_data *sharing);
t_philo_info	*init_philo_info(t_state_of_philo *state, t_shared_data *sharing);

/* about thread */
t_bool			create_threads(t_philo_info *info);
int				join_thread(t_philo_info *info, int num_of_success_thread);

/* about time */
ssize_t			get_row_now_time(void);
ssize_t			get_now_time(t_philo_info *info);

/* main lohic */
void  			monitor_philos(t_philo_info *info);

#endif
