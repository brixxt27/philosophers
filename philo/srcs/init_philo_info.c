/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:48:42 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/30 21:15:56 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_bool	init_philo_info(t_philo_info *info)
{
	info->thread = malloc(sizeof(pthread_t) * info->state.num_philo);
	if (info->thread == NULL)
		return (FAIL);
	return (SUCCESS);
}
