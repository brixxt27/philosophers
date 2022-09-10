/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time_to_start_per_philos.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:13:46 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:02:05 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time_to_start_per_philos(t_philo_info *info,
	ssize_t time_to_start)
{
	int	i;

	i = 0;
	while (i < info->state->num_philo)
	{
		info[i].time_to_start = time_to_start;
		i++;
	}
}
