#include "../inc/philosophers.h"

/* 세마포어를 생성하는 함수 */
void	init_prosses1(t_glob *info)
{
	char	*sem;
	int		i;

	i = -1;
	while (++i < info->nb_philos)
	{
		sem = ft_itoa(i);
		sem_unlink(sem);
		/*
		 * 마지막 인자값이 2인 경우 어떻게 될까요?
		 *  => 데드락에 걸리지 않습니다. 
		 *     (인접한 철학자들이 사이좋게 식사가 가능합니다 ^^) 
		 */
		info->forks[i] = sem_open(sem, O_CREAT, 0644, 1);
		free(sem);
	}
	sem_unlink("print");
	info->msg = sem_open("print", O_CREAT, 0644, 1);
}

/* Mandatory 부분과 동일 */
void	init_prosses2(t_philo *philos, t_glob *info)
{
	int				i;
	struct timeval	current_time;

	i = -1;
	while (++i < info->nb_philos)
	{
		gettimeofday(&current_time, NULL);
		info->start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
		philos[i].id = i + 1;
		philos[i].right = info->forks[i];
		philos[i].left = info->forks[(i + 1) % info->nb_philos];
		philos[i].info = info;
		philos[i].last_eat = get_current_time(info->start);
		philos[i].number_of_times = 0;
	}
}

/* 프로세스 정보 초기화 및 생성 함수 */
void	creat_prosses(t_philo *philos, t_glob *info)
{
	int	i;

	init_prosses1(info);
	init_prosses2(philos, info);
	i = -1;
	while (++i < info->nb_philos)
	{
		philos[i].pid = fork();
		/* i 번째 fork 실패시 => 0, 1, ..., i - 1 번째 자식 프로세스들을 종료시킵니다. */
		if (philos[i].pid == -1)
		{
			while (--i >= 0)
				kill(philos[i].pid, SIGINT);
			exit(0);
		}
		/* 
		 * 자식 프로세스에서는 main, philo 두 개의 스레드가 수행이 이뤄집니다. 
		 * - main : watch_thread 를 수행하면서 while 루프로 단 하나의 철학자만 관찰합니다.
		 * - philo : mandatory 에서 봤던 routin 함수를 동일한 방식으로 수행합니다.
		 */
		else if (philos[i].pid == 0)
		{
			pthread_create(&philos[i].philo, NULL, &philo_routin, &philos[i]);
			watch_thread(&philos[i]);
		}
		/* Deadlock 을 해결하기 위한 방법 : 약간의 딜레이를 줍니다. */
		usleep(100);
	}
}
