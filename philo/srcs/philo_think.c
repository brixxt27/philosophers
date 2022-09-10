/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:54:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 04:49:01 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_think(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	print_status(info, STR_THINK);
	return (SUCCESS);
}
