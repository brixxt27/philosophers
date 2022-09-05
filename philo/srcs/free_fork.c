/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:37:05 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 05:41:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_bool	free_fork(pthread_mutex_t *m_fork)
{
	free(m_fork);
	m_fork = NULL;
	return (FAIL);
}
