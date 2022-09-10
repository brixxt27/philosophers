/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:46:54 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 15:27:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int	is_die(t_philo_info *info)
{
	pthread_mutex_lock(&info->sharing->m_flag);
	if (get_now_time(info) - info->time_to_last_eat >= info->state->time_to_die)
	{
		pthread_mutex_unlock(&info->sharing->m_flag);
		return (1);
	}
	pthread_mutex_unlock(&info->sharing->m_flag);
	return (0);
}
