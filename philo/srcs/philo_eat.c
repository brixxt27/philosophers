/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:29:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 04:47:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_time_to_last_eat(t_philo_info *info)
{
	pthread_mutex_lock(&info->sharing->m_flag);
	info->time_to_last_eat = get_now_time(info);
	pthread_mutex_unlock(&info->sharing->m_flag);
}

t_bool	philo_eat(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	update_time_to_last_eat(info);
	print_status(info, STR_EAT);
	if (info->state->num_must_eat > 0)
	{
		info->num_eat++;
		pthread_mutex_lock(&info->sharing->m_seat);
		if (info->num_eat == info->state->num_must_eat)
			info->sharing->num_enough_eating++;
		pthread_mutex_unlock(&info->sharing->m_seat);
	}
	xusleep(info, info->state->time_to_eat);
	return (SUCCESS);
}
