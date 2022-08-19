/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:20:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 21:49:12 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo_info	info;

	if (check_exception(argc) == FAIL)
		return (1);
	if (init_philo_info(&info, argc, argv) == FAIL)
		return (1);
	// if (create_threads() == FAIL)
	// 	return (free_all());
	// if (do_routines_each_philo() == FAIL)
	// 	return (free_all());
	// if (watch_by_main_thread() == FAIL)
	// 	return (free_all());
	// // thread join? detach?
	// free_all();
	return (0);
}
