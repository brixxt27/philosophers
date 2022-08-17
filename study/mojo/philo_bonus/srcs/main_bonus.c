#include "../inc/philosophers.h"

/* 인자 검사 함수 */
int	args_control(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
	{
		printf("wrong args\n");
		return (1);
	}
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (ft_atoi(av[i]) <= 0 || av[i][j])
		{
			printf("wrong args\n");
			return (1);
		}
	}
	return (0);
}

/* 정보 세팅 */
int	set_info(t_glob *info, int nb_philos, int ac, char **av)
{
	info->forks = malloc(sizeof(sem_t *) * nb_philos);
	if (!(info->forks))
		return (0);
	info->nb_philos = nb_philos;
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->number_of_times = -1;
	if (ac == 6)
		info->number_of_times = ft_atoi(av[5]);
	return (1);
}

int	main(int ac, char **av)
{
	int				nb_philos;
	t_philo			*philos;
	t_glob			*info;

	if (args_control(ac, av))
		return (0);
	nb_philos = ft_atoi(av[1]);
	philos = malloc(sizeof(t_philo) * nb_philos);
	info = malloc(sizeof(t_glob));
	if (!philos || !info || !set_info(info, nb_philos, ac, av))
	{
		if (philos)
			free(philos);
		if (info)
			free(philos);
		return (0);
	}
	creat_prosses(philos, info);
	watch_prosses(philos);
	clear_sem(info, nb_philos);
	return (0);
}
