#include "../inc/philosophers.h"

long	get_current_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - start);
}

/*
 * 세마포어의 값은 0 이상임을 유의해주세요.
 *
 * sem_wait() 
 *  => 세마포어의 값을 1 감소시킵니다.
 *     만약, 0인 상태면 현재 수행중인 철학자 스레드는 blocking 됩니다. (즉, 대기 상태)
 *
 * sem_post()
 *  => 세마포어의 값을 1 증가시킵니다.
 *
 * Mandatory 랑 유사하게 진행되기 때문에 sem_wait, sem_post 함수에 대해 알아보시면 좋을듯 합니다.
 */
void	philo_eating(t_philo *philo)
{
	struct timeval	current_time;
	long			start;

	sem_wait(philo->right);
	sem_wait(philo->info->msg);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, R_FRK);
	sem_post(philo->info->msg);
	sem_wait(philo->left);
	sem_wait(philo->info->msg);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, L_FRK);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, EAT);
	sem_post(philo->info->msg);
	gettimeofday(&current_time, NULL);
	start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	while (get_current_time(start) < philo->info->time_to_eat)
		usleep(200);
	philo->last_eat = get_current_time(philo->info->start);
	if (philo->info->number_of_times > 0)
		philo->number_of_times++;
}

/* 철학자의 루틴이 수행되는 함수 */
void	*philo_routin(void *p)
{
	t_philo			*philo;
	struct timeval	current_time;
	long			start;

	philo = (t_philo *)p;
	while (TRUE)
	{
		philo_eating(philo);
		sem_post(philo->left);
		sem_post(philo->right);
		sem_wait(philo->info->msg);
		printf("%ld ms [%d]%s\n", \
			get_current_time(philo->info->start), philo->id, SLP);
		sem_post(philo->info->msg);
		gettimeofday(&current_time, NULL);
		start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
		while (get_current_time(start) < philo->info->time_to_sleep)
			usleep(100);
		sem_wait(philo->info->msg);
		printf("%ld ms [%d]%s\n", \
			get_current_time(philo->info->start), philo->id, THNK);
		sem_post(philo->info->msg);
	}
}

/* 세마포어에 대한 close 작업 */
void	clear_sem(t_glob *info, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		sem_close(info->forks[i]);
	sem_close(info->msg);
}
