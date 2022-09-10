/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:48:42 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 17:00:34 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_philo_info	*init_philo_info(t_state_of_philo *state, 
	t_shared_data *sharing)
{
	t_philo_info	*info;
	ssize_t				i;

	i = 0;
	info = (t_philo_info *)malloc(sizeof(t_philo_info) * state->num_philo);
	if (info == NULL)
		return (NULL);
	while (i < state->num_philo)
	{
		info[i].state = state;
		info[i].sharing = sharing;
		info[i].right_fork = &sharing->m_fork[i];
		if (i == 0)
			info[i].left_fork = &sharing->m_fork[state->num_philo - 1];
		else
			info[i].left_fork = &sharing->m_fork[i - 1];
		info[i].time_to_last_eat = 0;
		info[i].num_eat = 0;
		info[i].idx = i + 1;
		i++;
	}
	return (info);
}
