/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state_of_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:05:21 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 22:02:54 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philo.h"
#include <stdio.h>

static t_bool	atoi_and_check_error(char *str, ssize_t *num)
{
	*num = ft_atol(str);
	if (*num < 0 || *num > INT_MAX)
	{
		printf("Please put int type data of 0 or higher\n");
		return (FAIL);
	}
	return (SUCCESS);
}

t_bool	init_state_of_philo(t_state_of_philo *state, int argc, char *argv[])
{
	if (atoi_and_check_error(argv[1], &state->num_philo) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[2], &state->time_to_die) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[3], &state->time_to_eat) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[4], &state->time_to_sleep) == FAIL)
		return (FAIL);
	state->num_must_eat = -1;
	if (argc == 6)
	{
		if (atoi_and_check_error(argv[5], &state->num_must_eat) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}