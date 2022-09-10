/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:54:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:21:11 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	philo_think(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	print_status(info, STR_THINK);
	return (SUCCESS);
}
