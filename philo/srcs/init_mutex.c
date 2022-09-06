/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:06:58 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 23:35:49 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <philo.h>
#include <stdlib.h>
#include "ft_util.h"

static t_bool	init_print_mutex(pthread_mutex_t *m_print)
{
	int	ret;

	ret = pthread_mutex_init(m_print, NULL);
	if (ret != 0)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	malloc_m_fork(t_state_of_philo *state, pthread_mutex_t *m_fork)
{
	m_fork = malloc(sizeof(pthread_mutex_t) * state->num_philo);
	if (m_fork == NULL)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	init_fork_mutex(t_state_of_philo *state, \
	pthread_mutex_t *m_fork, int *pi)
{
	int	ret;

	ret = 0;
	while (*pi < state->num_philo)
	{
		ret = pthread_mutex_init(&m_fork[*pi], NULL);
		if (ret != 0)
			return (FAIL);
		*pi++;
	}	
	return (SUCCESS);
}

t_bool	init_mutex(t_state_of_philo *state, t_mutex_list *m_list)
{
	int	i;

	i = 0;
	if (init_print_mutex(&m_list->m_print) == SUCCESS)
	{
		if (malloc_m_fork(state, m_list->m_fork) == SUCCESS)
		{
			if (init_m_fork(state, m_list->m_fork, &i) == SUCCESS)
				return (SUCCESS); 
				// i 만큼 destroy mutex 해야 함
				// free m_fork
		}
		// destroy m_print
	}
	// free info
	return (FAIL);
}

/* 원래 작성한 함수인데 실패했을 때의 분기의 편의성 때문에 다시 작성 */
// t_bool	init_mutex(t_state_of_philo *state, t_mutex_list *m_list)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	if (init_print_mutex(&m_list->m_print) == FAIL)
// 		return (FAIL);
// 	m_list->m_fork = malloc(sizeof(pthread_mutex_t) * state->num_philo);
// 	if (m_list->m_fork == NULL)
// 		return (FAIL);
// 	while (i < state->num_philo)
// 	{
// 		ret = pthread_mutex_init(&m_list->m_fork[i], NULL);
// 		if (ret != 0)
// 			break ;
// 		i++;
// 	}	
// 	if (ret != 0)
// 	{
// 		// i 만큼 destroy mutex 해야 함
// 		return (free_fork(m_list->m_fork));
// 	}
// 	return (SUCCESS);
// }
