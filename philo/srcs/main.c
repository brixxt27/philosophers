/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/30 21:20:30 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



#include <stdio.h>
void	print_info(t_state_of_philo *info)
{
	printf("%zd\n", info->num_philo);
	printf("%zd\n", info->time_to_die);
	printf("%zd\n", info->time_to_eat);
	printf("%zd\n", info->time_to_sleep);
	printf("%zd\n", info->num_must_eat);
}

static int	join_thread(t_philo_info *info, int num_of_success_thread)
{
	int	i;

	i = num_of_success_thread;
	while (i > 0)
	{
		pthread_join(info->thread[i - 1], NULL);
		i--;
	}
	if (num_of_success_thread == info->state.num_philo)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_philo_info		info;
	int					num_of_success_thread;

	if (check_the_number_of_arguments(argc) == FAIL)
		return (1);
	if (init_state_of_philo(&info.state, argc, argv) == FAIL)
		return (1);
	if (init_philo_info(&info) == FAIL)
		return (1);
	// 실패 시 기존에 만든 thread 전부 수거
	num_of_success_thread = create_threads(&info);
	if (num_of_success_thread != info.state.num_philo)
		return (join_thread(&info, num_of_success_thread));
	// if (watch_by_main_thread() == FAIL)
	// 	return (free_all());
	// // thread join? detach?
	// free_all();
	print_info(&info.state);
	return (join_thread(&info, num_of_success_thread));
}
