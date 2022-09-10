/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xusleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:40:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 00:22:10 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	xusleep(t_philo_info *info, ssize_t state_time)
{
	ssize_t	time_to_start_xusleep;

	time_to_start_xusleep = get_now_time(info);
	while (get_now_time(info) - time_to_start_xusleep < state_time)
		usleep(300);
}
