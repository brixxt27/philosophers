/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_a_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:48:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 23:28:18 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	put_up_a_fork(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	// if (info->idx % 2 == 1)
	// {
	// 	pthread_mutex_lock(info->right_fork);
	// 	pthread_mutex_lock(&info->sharing->m_print);
	// 	printf("%lu %d %s\n", get_now_time(info), info->idx, STR_FORK);
	// 	pthread_mutex_unlock(&info->sharing->m_print);
	// 	pthread_mutex_lock(info->left_fork);
	// 	pthread_mutex_lock(&info->sharing->m_print);
	// 	printf("%lu %d %s\n", get_now_time(info), info->idx, STR_FORK);
	// 	pthread_mutex_unlock(&info->sharing->m_print);
	// }
	// else
	// {
		pthread_mutex_lock(info->left_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d %s\n", get_now_time(info), info->idx, STR_FORK);
		pthread_mutex_unlock(&info->sharing->m_print);
		pthread_mutex_lock(info->right_fork);
		pthread_mutex_lock(&info->sharing->m_print);
		printf("%lu %d %s\n", get_now_time(info), info->idx, STR_FORK);
		pthread_mutex_unlock(&info->sharing->m_print);
	// }
	return (SUCCESS);
}
