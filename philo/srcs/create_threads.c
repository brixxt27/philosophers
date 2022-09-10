/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:28:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 10:53:20 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

// static void	*routine_think(t_philo_info *info)
// {
	
// }

#include <stdio.h>
static void	*do_routine_each_philo(void *fptr)
{
	t_philo_info	*info;

	info = (t_philo_info *)fptr;
	pthread_mutex_lock(&info->sharing->m_seat);
	info->sharing->num_seat++;
	pthread_mutex_unlock(&info->sharing->m_seat);
	pthread_mutex_lock(&info->sharing->m_flag);
	pthread_mutex_unlock(&info->sharing->m_flag);
	while (1)
	{
		if (put_up_a_fork(info) == FAIL)
			break ;
		if (put_down_a_fork(info) == FAIL)
			break ;
		// if (routine_think(info) == FAIL)
		// 	break ;
		// fsanitize 관찰용 usleep
		usleep(1000);
	}
	// die
	pthread_mutex_lock(&info->sharing->m_flag);
	info->sharing->flag_dead = DEAD;
	pthread_mutex_unlock(&info->sharing->m_flag);
	printf("die\n");
	return ((void *)info);
}

t_bool	create_threads(t_philo_info *info)
{
	ssize_t	i;
	int		ret;

	i = 0;
	pthread_mutex_lock(&info->sharing->m_flag);
	while (i < info->state->num_philo)
	{
		ret = pthread_create(&info[i].tid, NULL, do_routine_each_philo, \
								&info[i]);
		if (ret != 0)
			break ;
		i++;
	}
	return (i);
}
