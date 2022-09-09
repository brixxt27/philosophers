/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_a_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:48:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 00:03:21 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	put_up_a_fork(t_philo_info *info)
{
	if (is_die(info))
		return (FAIL);
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
	return (SUCCESS);
}
