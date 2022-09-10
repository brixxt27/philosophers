/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:16:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 19:13:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	wait_to_create_all_philos(t_philo_info *info)
{
	while (1)
	{
		pthread_mutex_lock(&info->sharing->m_seat);
		if (info->sharing->num_seat == info->state->num_philo)
		{
			pthread_mutex_unlock(&info->sharing->m_seat);
			break ;
		}
		pthread_mutex_unlock(&info->sharing->m_seat);
		usleep(100);
	}
}

static void	init_time_to_start_per_philos(t_philo_info *info, 
	ssize_t time_to_start)
{
	int	i;

	i = 0;
	while (i < info->state->num_philo)
	{
		info[i].time_to_start = time_to_start;
		i++;
	}
}

static int	is_eat_enough(t_philo_info *info)
{
	if (info->state->num_must_eat > 0)
	{
		pthread_mutex_lock(&info->sharing->m_seat);
		if (info->num_eat >= info->state->num_must_eat)
		{
			pthread_mutex_unlock(&info->sharing->m_seat);
			return (1);
		}
		pthread_mutex_unlock(&info->sharing->m_seat);
	}
	return (0);
}

void  monitor_philos(t_philo_info *info)
{
	ssize_t time_to_start;
	int		i;
	int		flag_die;

	i = 0;
	flag_die = 0;
	wait_to_create_all_philos(info);
	time_to_start = get_row_now_time();
	init_time_to_start_per_philos(info, time_to_start);
	pthread_mutex_unlock(&info->sharing->m_flag);
	while (1)
	{
		if (i >= info->state->num_philo)
			i = 0;
		if (is_die(&info[i]))
		{
			flag_die = 1;
			break ;
		}
		if (is_eat_enough(&info[i]))
		{
			if (++info->sharing->num_enough_eating == info->state->num_philo)
				break ;
		}
		usleep(100);
		i++;
	}
	if (flag_die)
	{
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d %s\n", get_now_time(info), info->idx, STR_DIE);
		pthread_mutex_unlock(&info->sharing->m_print);
	}
}

		// pthread_mutex_lock(&info->sharing->m_flag);
		// if (info->sharing->flag_dead == DEAD)
		// {
		// 	pthread_mutex_unlock(&info->sharing->m_flag);
		// 	break ;
		// }
		// pthread_mutex_unlock(&info->sharing->m_flag);
