/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:48:42 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/01 19:52:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_philo_info	*init_philo_info(t_state_of_philo *state)
{
	t_philo_info	*info;
	ssize_t				i;

	i = 0;
	info = malloc(sizeof(pthread_t) * state->num_philo);
	if (info == NULL)
		return (NULL);
	while (i < state->num_philo)
	{
		info[i].state = state;
		i++;
	}
	return (info);
}
