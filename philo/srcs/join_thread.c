/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:41:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 10:51:19 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_thread(t_philo_info *info, int num_of_success_thread)
{
	int	i;

	i = 0;
	while (i < num_of_success_thread)
	{
		pthread_join(info[i].tid, NULL);
		i++;
	}
}
