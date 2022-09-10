/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:54:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 20:58:38 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	philo_think(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	pthread_mutex_lock(&info->sharing->m_print);
	printf("%lu %d %s\n", get_now_time(info), info->idx, STR_THINK);
	pthread_mutex_unlock(&info->sharing->m_print);
	return (SUCCESS);
}
