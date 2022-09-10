/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:16:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 04:39:12 by jayoon           ###   ########.fr       */
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

static int	do_monitor(t_philo_info *info)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i >= info->state->num_philo)
		{
			i = 0;
			usleep(100);
		}
		if (is_die(&info[i]))
		{
			info->sharing->flag_dead = DEAD;
			pthread_mutex_unlock(&info->sharing->m_flag);
			break ;
		}
		pthread_mutex_unlock(&info->sharing->m_flag);
		if (is_eat_enough(info))
			break ;
		i++;
	}
	return (i);
}

void	monitor_philos(t_philo_info *info)
{
	ssize_t	time_to_start;
	int		idx_philo;

	wait_to_create_all_philos(info);
	time_to_start = get_row_now_time();
	init_time_to_start_per_philos(info, time_to_start);
	pthread_mutex_unlock(&info->sharing->m_flag);
	idx_philo = do_monitor(info);
	pthread_mutex_lock(&info->sharing->m_flag);
	if (info->sharing->flag_dead)
	{
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d %s\n", get_now_time(info), info[idx_philo].idx, STR_DIE);
		pthread_mutex_unlock(&info->sharing->m_print);
	}
	pthread_mutex_unlock(&info->sharing->m_flag);
}
