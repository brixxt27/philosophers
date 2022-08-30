/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/30 20:55:11 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

typedef enum e_bool
{
	SUCCESS,
	FAIL
}	t_bool;

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
	pthread_t			*thread;
	t_state_of_philo	state;
}	t_philo_info;

t_bool	check_the_number_of_arguments(int argc);
t_bool	init_state_of_philo(t_state_of_philo *state, int argc, char *argv[]);
t_bool	init_philo_info(t_philo_info *info);
t_bool	create_threads(t_philo_info *info);

#endif
