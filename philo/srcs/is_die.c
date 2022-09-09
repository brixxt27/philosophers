/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:46:54 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 00:12:41 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int	is_die(t_philo_info *info)
{
	if (get_now_time(info) - info->time_to_last_eat >= info->state->time_to_die)
		return (1);
	return (0);
}
