/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eat_enough.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:11:42 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 20:11:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat_enough(t_philo_info *info)
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
