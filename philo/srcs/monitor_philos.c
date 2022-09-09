/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:16:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/09 23:02:49 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


#include <stdio.h>

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

void  monitor_philos(t_philo_info *info)
{
	ssize_t time_to_start;

	while (1)
	{
		pthread_mutex_lock(&info->sharing->m_seat);
		if (info->sharing->num_seat == info->state->num_philo)
			break ;
		pthread_mutex_unlock(&info->sharing->m_seat);
		usleep(1);
	}
	// 이 아래로 메인이 오지 않음
	time_to_start = get_row_now_time();
	init_time_to_start_per_philos(info, time_to_start);
	pthread_mutex_unlock(&info->sharing->m_flag);
	while (1)
	;
}
