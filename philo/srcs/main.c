/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 23:36:45 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"
#include "philo.h"


// system()
#include <stdlib.h>
// printf()
#include <stdio.h>
void	print_state(t_state_of_philo *state)
{
	printf("%zd\n", state->num_philo);
	printf("%zd\n", state->time_to_die);
	printf("%zd\n", state->time_to_eat);
	printf("%zd\n", state->time_to_sleep);
	printf("%zd\n", state->num_must_eat);
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
		return (free_fork(m_list.m_fork));
	num_of_success_thread = create_threads(info);
	// if (num_of_success_thread != state.num_philo)
	// {
	// 	free_all(info);
	// 	return (join_thread(info, num_of_success_thread));
	// }
	// monitor_philos(info);
	// free_all(info);
	// mutex destroy
	return (join_thread(info, num_of_success_thread));
}

	// print_state(&state);
	// system("leaks philo");

