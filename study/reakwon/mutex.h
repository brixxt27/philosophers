#ifndef MUTEX_H
# define MUTEX_H

typedef struct s_philo
{
	size_t			id;
	pthread_t		thread;
	char			*name;
	pthread_mutex_t	*mutex;
}	t_philo;

typedef struct s_util
{
	t_philo			*philo;
}   t_util;

int				cnt;

#endif
