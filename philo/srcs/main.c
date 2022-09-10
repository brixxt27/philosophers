/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/10 22:21:28 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"
#include "philo.h"

static t_bool	destroy_mutex(t_shared_data *sharing, int num_of_thread)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&sharing->m_flag);
	pthread_mutex_destroy(&sharing->m_print);
	pthread_mutex_destroy(&sharing->m_seat);
	// 스레드 성공과 상관 없이 모두 destroy
	while (i < num_of_thread)
	{
		pthread_mutex_destroy(&sharing->m_fork[i]);
		i++;
	}
	return (FAIL);
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
	// free m_fork
		return (destroy_mutex(&sharing, state.num_philo));
	num_of_success_thread = create_threads(info);
	if (num_of_success_thread != state.num_philo)
	{
		join_thread(info, num_of_success_thread);
		destroy_mutex(&sharing, num_of_success_thread);
		return (free_all(info, num_of_success_thread));
	}
	monitor_philos(info);
	join_thread(info, num_of_success_thread);
	destroy_mutex(&sharing, num_of_success_thread);
	return (free_all(info, num_of_success_thread));
}
