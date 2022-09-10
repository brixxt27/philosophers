/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routine_each_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:31:47 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:19:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	wait_to_create_all_threads(t_philo_info *info)
{
	pthread_mutex_lock(&info->sharing->m_seat);
	info->sharing->num_seat++;
	pthread_mutex_unlock(&info->sharing->m_seat);
	pthread_mutex_lock(&info->sharing->m_flag);
	pthread_mutex_unlock(&info->sharing->m_flag);
}

static void	wait_even_numbers(t_philo_info *info)
{
	if (info->idx % 2)
		xusleep(info, info->state->time_to_eat / 2);
}

static void	routine_one_philo(t_philo_info *info)
{
	print_status(info, STR_FORK);
	xusleep(info, info->state->time_to_die);
}

static void	routine_philos(t_philo_info *info)
{
	while (1)
	{
		if (put_up_a_fork(info) == FAIL)
			break ;
		if (philo_eat(info) == FAIL)
			break ;
		if (put_down_a_fork(info) == FAIL)
			break ;
		if (philo_sleep(info) == FAIL)
			break ;
		if (philo_think(info) == FAIL)
			break ;
	}
	pthread_mutex_unlock(info->left_fork);
	pthread_mutex_unlock(info->right_fork);
}

void	*do_routine_each_philo(void *fptr)
{
	t_philo_info	*info;

	info = (t_philo_info *)fptr;
	wait_to_create_all_threads(info);
	wait_even_numbers(info);
	if (info->state->num_philo == 1)
		routine_one_philo(info);
	else
		routine_philos(info);
	return ((void *)info);
}
