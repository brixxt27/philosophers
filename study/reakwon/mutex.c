#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mutex.h"

void	*count(void *philo)
{
	int		i;
	t_philo	*p = (t_philo *)philo;

	pthread_mutex_lock(p->mutex);
	/* critical section*/
	for (i = 0; i < 10; i++)
	{
		printf("%s, %zu cnt: %d\n", p->name, p->id, cnt);
		cnt++;
		usleep(1);
	}
	/* critical section */
	pthread_mutex_unlock(p->mutex);
}

int	main(int ac, char **av)
{
	t_util			util;
	pthread_mutex_t	mutex;
	size_t			i;

	if (ac != 3)
	{
		printf("Put in 3 arguments\n");
		exit(1);
	}

	i = 0;
	util.philo = malloc(sizeof(t_philo *) * ac - 1);
	for (i = 0; i < 2; i++)
	{
		util.philo[i].id = i;
		util.philo[i].name = av[i + 1];
	}
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 2; i++)
		util.philo[i].mutex = &mutex;
	
	for (i = 0; i < 2; i++)
		pthread_create(&util.philo[i].thread, NULL, count, &util.philo[i]);
	
	for (i = 0; i < 2; i++)
		pthread_join(util.philo[i].thread, NULL);

	pthread_mutex_destroy(&mutex);
	return (0);
}
