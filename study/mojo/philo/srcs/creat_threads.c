#include "../inc/philosophers.h"

/* 철학자 스레드가 생성되는 함수 */
void	creat_threads(t_philo *philos, t_glob *info)
{
	int				i;
	struct timeval	current_time;

	i = -1;
	/* 포크 및 프린트 뮤텍스 초기화 */
	while (++i < info->nb_philos)
		pthread_mutex_init(&info->forks[i], NULL);
	pthread_mutex_init(&info->msg, NULL);
	i = -1;
	/* 철학자들 정보 초기화 */
	while (++i < info->nb_philos)
	{
		gettimeofday(&current_time, NULL);
		info->start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
		philos[i].id = i + 1;
		philos[i].right = &info->forks[i];
		philos[i].left = &info->forks[(i + 1) % info->nb_philos];
		philos[i].info = info;
		philos[i].last_eat = get_current_time(info->start);
		philos[i].number_of_times = 0;
	}
	i = -1;
	/* 철학자 스레드를 생성 */
	while (++i < info->nb_philos)
	{
		pthread_create(&philos[i].philo, NULL, &philo_routin, &philos[i]);
		usleep(100); // Why? => 한 번에 철학자가 놓여질 경우 Deadlock
					 // Solution => 0.1 ms 딜레이 설정(각 철학자가 두 개의 포크를 들도록 함) 
	}
}
