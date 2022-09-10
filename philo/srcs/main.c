/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/11 01:01:33 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"
#include "philo.h"
#include <stdlib.h>

static t_bool	destroy_mutex(t_shared_data *sharing, int num_philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&sharing->m_flag);
	pthread_mutex_destroy(&sharing->m_print);
	pthread_mutex_destroy(&sharing->m_seat);
	while (i < num_philo)
	{
		pthread_mutex_destroy(&sharing->m_fork[i]);
		i++;
	}
	return (FAIL);
}

static int	free_m_fork(t_shared_data *sharing)
{
	free(sharing->m_fork);
	sharing->m_fork = NULL;
	return (1);
}

static void	clear_thread_and_mutex(t_philo_info *info,
	int num_of_success_thread, t_shared_data *sharing, t_state_of_philo *state)
{
	join_thread(info, num_of_success_thread);
	destroy_mutex(sharing, state->num_philo);
}

int	main(int argc, char *argv[])
{
	t_philo_info		*info;
	t_state_of_philo	state;
	t_shared_data		sharing;
	int					num_of_success_thread;

	if (init_state_of_philo(&state, argc, argv) == FAIL)
		return (1);
	if (init_mutex_and_shared_data(&state, &sharing) == FAIL)
		return (1);
	info = init_philo_info(&state, &sharing);
	if (info == NULL)
	{
		free_m_fork(&sharing);
		return (destroy_mutex(&sharing, state.num_philo));
	}
	num_of_success_thread = create_threads(info);
	if (num_of_success_thread != state.num_philo)
	{
		clear_thread_and_mutex(info, num_of_success_thread, &sharing, &state);
		return (free_all(info, num_of_success_thread));
	}
	monitor_philos(info);
	clear_thread_and_mutex(info, num_of_success_thread, &sharing, &state);
	return (free_all(info, num_of_success_thread));
}
