/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:50:31 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/06 05:42:41 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "philo.h"
# include <unistd.h>

ssize_t	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_issign(int c);
int		ft_isspace(int c);
t_bool	free_fork(pthread_mutex_t *m_fork);
void	free_all(t_philo_info *info);

#endif
