/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eat_enough.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:11:42 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 04:52:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat_enough(t_philo_info *info)
{
	pthread_mutex_lock(&info->sharing->m_seat);
	if (info->sharing->num_enough_eating == info->state->num_philo)
	{
		pthread_mutex_lock(&info->sharing->m_flag);
		info->sharing->flag_full = FULL;
		pthread_mutex_unlock(&info->sharing->m_flag);
		pthread_mutex_unlock(&info->sharing->m_seat);
		return (1);
	}
	pthread_mutex_unlock(&info->sharing->m_seat);
	return (0);
}
