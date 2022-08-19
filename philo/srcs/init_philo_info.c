/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:05:21 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 21:54:18 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "philo.h"

static t_bool	atoi_and_check_error(char *str, ssize_t *num)
{
	*num = ft_atol(str);
	if (*num < 0 || *num > INT_MAX)
		return (FAIL);
	return (SUCCESS);
}

t_bool	init_philo_info(t_philo_info *info, int argc, char *argv[])
{
	if (atoi_and_check_error(argv[1], &info->num_philo) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[2], &info->time_to_die) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[3], &info->time_to_eat) == FAIL)
		return (FAIL);
	if (atoi_and_check_error(argv[4], &info->time_to_sleep) == FAIL)
		return (FAIL);
	info->num_must_eat = -1;
	if (argc == 6)
	{
		if (atoi_and_check_error(argv[5], &info->num_must_eat) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}
