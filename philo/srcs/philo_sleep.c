/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:50:57 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:20:53 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	philo_sleep(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	print_status(info, STR_SLEEP);
	xusleep(info, info->state->time_to_sleep);
	return (SUCCESS);
}
