/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:13:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:34:13 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_status(t_philo_info *info, char *status)
{
	pthread_mutex_lock(&info->sharing->m_flag);
	if (info->sharing->flag_dead == DEAD)
	{
		pthread_mutex_unlock(&info->sharing->m_flag);
		return ;
	}
	pthread_mutex_lock(&info->sharing->m_print);
	printf("%lu %d %s\n", get_now_time(info), info->idx, status);
	pthread_mutex_unlock(&info->sharing->m_print);
	pthread_mutex_unlock(&info->sharing->m_flag);
}
