/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 05:45:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

# define ALIVE	1

typedef enum e_bool
{
	SUCCESS,
	FAIL
}	t_bool;

typedef struct s_mutex_list
{
	pthread_mutex_t	m_print;
	pthread_mutex_t	*m_fork;
}	t_mutex_list;

typedef struct s_state_of_philo
{
	ssize_t		num_philo;
	ssize_t		time_to_die;
	ssize_t		time_to_eat;
	ssize_t		time_to_sleep;
	ssize_t		num_must_eat;
}	t_state_of_philo;

typedef struct s_philo_info
{
	pthread_t			tid;
	t_state_of_philo	*state;
	t_mutex_list		*m_list;
	ssize_t				last_time_to_eat;
	int					idx;
}	t_philo_info;

/* check exeception and init variable */
t_bool			check_the_number_of_arguments(int argc);
t_bool			init_state_of_philo(t_state_of_philo *state, int argc, \
					char *argv[]);
t_bool			init_mutex(t_state_of_philo *state, t_mutex_list *m_list);
t_philo_info	*init_philo_info(t_state_of_philo *state, t_mutex_list *m_list);

/* about thread */
t_bool			create_threads(t_philo_info *info);
int				join_thread(t_philo_info *info, int num_of_success_thread);

/* main lohic */
void  			monitor_philos(t_philo_info *info);

#endif
