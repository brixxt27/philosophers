/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:54:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 10:18:20 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	free_all(t_philo_info *info, int num_success_philo)
{
	int	num_philo;

	num_philo = info->state->num_philo;
	free(info->sharing->m_fork);
	info->sharing->m_fork = NULL;
	free(info);
	info = NULL;
	if (num_philo == num_success_philo)
		return (0);
	return (1);
}
