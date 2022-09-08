/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:06:58 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/07 17:53:49 by jayoon           ###   ########.fr       */
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

static t_bool	malloc_m_fork(t_state_of_philo *state, t_mutex_list *m_list)
{
	m_list->m_fork = malloc(sizeof(pthread_mutex_t) * state->num_philo);
	if (m_list->m_fork == NULL)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	init_m_fork(t_state_of_philo *state, \
	t_mutex_list *m_list, int *pi)
{
	int	ret;

	ret = 0;
	while (*pi < state->num_philo)
	{
		ret = pthread_mutex_init(&m_list->m_fork[*pi], NULL);
		if (ret != 0)
			return (FAIL);
		(*pi)++;
	}	
	return (SUCCESS);
}

static void	destroy_and_free_m_fork(t_mutex_list *m_list, int i)
{
	int	idx;

	idx = 0;
	while (idx < i)
	{
		pthread_mutex_destroy(&m_list->m_fork[idx]);
		idx++;
	}
	free(m_list->m_fork);
	m_list->m_fork = NULL;
}

t_bool	init_mutex(t_state_of_philo *state, t_mutex_list *m_list)
{
	int	i;

	i = 0;
	if (init_a_mutex(&m_list->m_print) == SUCCESS)
	{
		if (malloc_m_fork(state, m_list) == SUCCESS)
		{
			if (init_m_fork(state, m_list, &i) == SUCCESS)
			{
				if (init_a_mutex(&m_list->m_flag_dead) == SUCCESS)
					return (SUCCESS); 
			}
			destroy_and_free_m_fork(m_list, i);
		}
		pthread_mutex_destroy(&m_list->m_print);
	}
	return (FAIL);
}
