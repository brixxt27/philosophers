/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_down_a_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:13:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 00:13:55 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	put_down_a_fork(t_philo_info *info)
{
	if (is_die(info))
		return (FAIL);
	if (info->idx % 2 == 1)
	{
		pthread_mutex_unlock(info->right_fork);
		pthread_mutex_unlock(info->left_fork);
	}
	else
	{
		pthread_mutex_unlock(info->left_fork);
		pthread_mutex_unlock(info->right_fork);
	}
	return (SUCCESS);
}
