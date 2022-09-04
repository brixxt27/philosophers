/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:28:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/04 22:17:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <sys/time.h>

static ssize_t	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static int	is_die(t_philo_info *info)
{
	if (get_now_time() - info->last_time_to_eat > info->state->time_to_die)
		return (1);
	return (0);
}

static void	*do_routine_each_philo(void *fptr)
{
	t_philo_info	*info;

	info = (t_philo_info *)fptr;
	while (1)
	{
		if (is_die(info))
			break ;
		routine_think();
		if (is_die(info))
			break ;
		routine_eat();
		if (is_die(info))
			break ;
		routine_sleep();
	}
	return ((void *)info);
}

t_bool	create_threads(t_philo_info *info)
{
	ssize_t	i;
	int		ret;

	i = 0;
	while (i < info->state->num_philo)
	{
		ret = pthread_create(&info[i].thread, NULL, do_routine_each_philo, \
								&info[i]);
		if (ret != 0)
			break ;
		i++;
	}
	return (i);
}
