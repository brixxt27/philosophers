/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:41:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/05 16:30:16 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_thread(t_philo_info *info, int num_of_success_thread)
{
	int	i;

	i = 0;
	while (i < num_of_success_thread)
	{
		pthread_join(info[i].tid, NULL);
		i++;
	}
	if (num_of_success_thread == info->state->num_philo)
		return (0);
	return (1);
}
