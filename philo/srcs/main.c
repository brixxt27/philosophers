/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/08 20:13:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"
#include "philo.h"

static void	destroy_mutex(t_mutex_list *m_list, int num_of_thread)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&m_list->m_flag_dead);
	pthread_mutex_destroy(&m_list->m_print);
	while (i < num_of_thread)
	{
		pthread_mutex_destroy(&m_list->m_fork[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo_info		*info;
	t_state_of_philo	state;
	t_mutex_list		m_list;
	int					num_of_success_thread;

	if (check_the_number_of_arguments(argc) == FAIL)
		return (1);
	if (init_state_of_philo(&state, argc, argv) == FAIL)
		return (1);
	info = init_philo_info(&state, &m_list);
	if (info == NULL)
		return (1);
	if (init_mutex(&state, &m_list) == FAIL)
		return (free_info(info));
	num_of_success_thread = create_threads(info);
	// if (num_of_success_thread != state.num_philo)
	// {
	// 	free_all(info);
	// 	destroy_mutex(&m_list, num_of_success_thread);
	// 	return (join_thread(info, num_of_success_thread));
	// }
	// monitor_philos(info);
	// free_all(info);
	destroy_mutex(&m_list, num_of_success_thread);
	return (join_thread(info, num_of_success_thread));
}
