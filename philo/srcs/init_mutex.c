/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:06:58 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 05:41:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <philo.h>
#include <stdlib.h>
#include "ft_util.h"

t_bool	init_mutex(t_state_of_philo *state, t_mutex_list *m_list)
{
	int	i;
	int	ret;

	i = 0;
	ret = pthread_mutex_init(m_list->m_fork, NULL);
	if (ret != 0)
		return (FAIL);
	m_list->m_fork = malloc(sizeof(state->num_philo));
	if (m_list->m_fork == NULL)
		return (FAIL);
	while (i < state->num_philo)
	{
		ret = pthread_mutex_init(&m_list->m_fork[i], NULL);
		if (ret != 0)
			break ;
		i++;
	}	
	if (ret != 0)
		return (free_fork(m_list->m_fork));
	return (SUCCESS);
}
