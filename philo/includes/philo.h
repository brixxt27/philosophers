/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 21:50:09 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>

typedef enum e_bool
{
	SUCCESS,
	FAIL
}	t_bool;

typedef enum e_argc
{
	ARGC_FIVE = -2,
	ARGC_SIX
}	t_argc;

typedef struct s_philo_info
{
	ssize_t	num_philo;
	ssize_t	time_to_die;
	ssize_t	time_to_eat;
	ssize_t	time_to_sleep;
	ssize_t	num_must_eat;
}	t_philo_info;

t_bool	check_exception(int argc);
t_bool	init_philo_info(t_philo_info *info, int argc, char *argv[]);

#endif
