/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_a_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:48:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:21:44 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	put_up_a_fork(t_philo_info *info)
{
	if (check_flag_die(info))
		return (FAIL);
	pthread_mutex_lock(info->left_fork);
	print_status(info, STR_FORK);
	pthread_mutex_lock(info->right_fork);
	print_status(info, STR_FORK);
	return (SUCCESS);
}
