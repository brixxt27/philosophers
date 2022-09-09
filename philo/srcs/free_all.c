/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:54:37 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/08 20:45:57 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	free_all(t_philo_info *info)
{
	free(info->sharing->m_fork);
	info->sharing->m_fork = NULL;
	free(info);
	info = NULL;
}
