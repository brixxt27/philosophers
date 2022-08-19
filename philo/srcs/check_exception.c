/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:04:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/19 21:04:23 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	check_exception(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("The number of parameters must be five of six.\n");
		return (FAIL);
	}
	return (SUCCESS);
}
