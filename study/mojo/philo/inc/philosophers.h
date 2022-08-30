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
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_glob
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	long			start;
	pthread_mutex_t	msg;
	pthread_mutex_t	*forks;
}	t_glob;

typedef struct s_philo
{
	int				id;
	int				number_of_times;
	long			last_eat;
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_glob			*info;
}	t_philo;

int		ft_atoi(const char *str);
void	creat_threads(t_philo *philos, t_glob *info);
int		watch_threads(t_philo *philos);
int		exit_threads(int ex, t_philo *philo);
void	philo_eating(t_philo *philo);
void	*philo_routin(void *p);
void	clear_mutex(t_glob *info, int size);
int		args_control(int ac, char **av);
long	get_current_time(long start);

#endif
