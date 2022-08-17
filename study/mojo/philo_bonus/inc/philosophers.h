/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:57:42 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/03/02 14:33:58 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 1
# define FALSE 0

# define R_FRK  ": has taken a right fork"
# define L_FRK  ": has taken a left fork"
# define EAT  ": is eating"
# define SLP  ": is sleeping"
# define THNK  ": is thinking"
# define DIED  ": is dead"
# define FINISH  ": simulation is finished"

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>

typedef struct s_glob
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	long			start;
	sem_t			*msg;
	sem_t			**forks;
}	t_glob;

typedef struct s_philo
{
	int				id;
	int				number_of_times;
	pid_t			pid;
	long			last_eat;
	pthread_t		philo;
	sem_t			*left;
	sem_t			*right;
	t_glob			*info;
}	t_philo;

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	init_prosses1(t_glob *info);
void	init_prosses2(t_philo *philos, t_glob *info);
void	creat_prosses(t_philo *philos, t_glob *info);
int		watch_prosses(t_philo *philos);
void	watch_thread(t_philo *philo);
void	philo_eating(t_philo *philo);
void	*philo_routin(void *p);
void	clear_sem(t_glob *info, int size);
int		args_control(int ac, char **av);
long	get_current_time(long start);

#endif