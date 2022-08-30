/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:28:30 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/30 21:17:06 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	*do_routine_each_philo(void *info)
{
	return (info);
}

t_bool	create_threads(t_philo_info *info)
{
	ssize_t	i;
	int		ret;

	i = 0;
	while (i < info->state.num_philo)
	{
		ret = pthread_create(info->thread, NULL, do_routine_each_philo, info);
		if (ret != 0)
			break ;
		i++;
	}
	return (i);
}
