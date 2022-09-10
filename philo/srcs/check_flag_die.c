/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:38:39 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 20:42:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_flag_die(t_philo_info *info)
{
	pthread_mutex_lock(&info->sharing->m_flag);
	if (info->sharing->flag_dead == DEAD)
	{
		pthread_mutex_unlock(&info->sharing->m_flag);
		return (1);
	}
	pthread_mutex_unlock(&info->sharing->m_flag);
	return (0);
}
