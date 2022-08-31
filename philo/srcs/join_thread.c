/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:41:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/31 21:41:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_thread(t_philo_info *info, int num_of_success_thread)
{
	int	i;

	i = num_of_success_thread;
	while (i > 0)
	{
		pthread_join(info->thread[i - 1], NULL);
		i--;
	}
	if (num_of_success_thread == info->state.num_philo)
		return (0);
	return (1);
}
