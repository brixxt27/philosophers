/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_and_shared_data.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:06:58 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/09 23:31:17 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <philo.h>
#include <stdlib.h>
#include "ft_util.h"

static t_bool	init_a_mutex(pthread_mutex_t *mutex)
{
	int	ret;

	ret = pthread_mutex_init(mutex, NULL);
	if (ret != 0)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	malloc_m_fork(t_state_of_philo *state, t_shared_data *sharing)
{
	sharing->m_fork = malloc(sizeof(pthread_mutex_t) * state->num_philo);
	if (sharing->m_fork == NULL)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	init_m_fork(t_state_of_philo *state, \
	t_shared_data *sharing, int *pi)
{
	int	ret;

	ret = 0;
	while (*pi < state->num_philo)
	{
		ret = pthread_mutex_init(&sharing->m_fork[*pi], NULL);
		if (ret != 0)
			return (FAIL);
		(*pi)++;
	}	
	return (SUCCESS);
}

static void	destroy_and_free_m_fork(t_shared_data *sharing, int i)
{
	int	idx;

	idx = 0;
	while (idx < i)
	{
		pthread_mutex_destroy(&sharing->m_fork[idx]);
		idx++;
	}
	free(sharing->m_fork);
	sharing->m_fork = NULL;
}

t_bool	init_mutex_and_shared_data(t_state_of_philo *state, 
	t_shared_data *sharing)
{
	int	i;

	sharing->num_seat = 0;
	sharing->flag_dead = ALIVE;
	i = 0;
	if (init_a_mutex(&sharing->m_print) == SUCCESS)
	{
		if (malloc_m_fork(state, sharing) == SUCCESS)
		{
			if (init_m_fork(state, sharing, &i) == SUCCESS)
			{
				if (init_a_mutex(&sharing->m_flag) == SUCCESS)
				{
					if (init_a_mutex(&sharing->m_seat) == SUCCESS)
						return (SUCCESS); 
				}
			}
			destroy_and_free_m_fork(sharing, i);
		}
		pthread_mutex_destroy(&sharing->m_print);
	}
	return (FAIL);
}
