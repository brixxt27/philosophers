/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:28:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/09 23:09:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <sys/time.h>

// static int	is_die(t_philo_info *info)
// {
// 	if (get_now_time() - info->time_to_last_eat > info->state->time_to_die)
// 		return (1);
// 	return (0);
// }

// static void	*routine_think(t_philo_info *info)
// {
	
// }

#include <stdio.h>
static void	put_up_a_fork(t_philo_info *info)
{
	if (info->idx % 2 == 1)
	{
		pthread_mutex_lock(info->right_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d has taken a fork\n", get_now_time(info), info->idx);
		pthread_mutex_unlock(&info->sharing->m_print);
		pthread_mutex_lock(info->left_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d has taken a fork\n", get_now_time(info), info->idx);
		pthread_mutex_unlock(&info->sharing->m_print);
	}
	else
	{
		pthread_mutex_lock(info->left_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d has taken a fork\n", get_now_time(info), info->idx);
		pthread_mutex_unlock(&info->sharing->m_print);
		pthread_mutex_lock(info->right_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d has taken a fork\n", get_now_time(info), info->idx);
		pthread_mutex_unlock(&info->sharing->m_print);
	}
}

static void	put_down_a_fork(t_philo_info *info)
{
	if (info->idx % 2 == 1)
	{
		pthread_mutex_unlock(info->right_fork);
		pthread_mutex_unlock(info->left_fork);
	}
	else
	{
		pthread_mutex_unlock(info->left_fork);
		pthread_mutex_unlock(info->right_fork);
	}

}

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
		put_up_a_fork(info);
		put_down_a_fork(info);
		// if (routine_think(info) == FAIL)
		// 	break ;
		// fsanitize 관찰
		usleep(100000);
	}
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
