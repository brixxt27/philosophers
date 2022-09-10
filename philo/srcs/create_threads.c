/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:28:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 21:25:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	create_threads(t_philo_info *info)
{
	ssize_t	i;
	int		ret;

	i = 0;
	pthread_mutex_lock(&info->sharing->m_flag);
	while (i < info->state->num_philo)
	{
		ret = pthread_create(&info[i].tid, NULL, do_routine_each_philo, \
								&info[i]);
		if (ret != 0)
			break ;
		i++;
	}
	return (i);
}
