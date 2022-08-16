#include "../inc/philosophers.h"

/* 쓰레드 종료 처리 */
int	exit_threads(int ex, t_philo *philo)
{
	/*
     * 특정 철학자가 종료될 때 "msg" lock 을 걸어주는 이유는 뭘까요?
	 *  => philo_routin 함수는 "msg" lock 을 걸어주고 어떤 작업을 했다고 
	 *     출력한 후 "msg" unlock 을 합니다.
	 *     즉, 메인 스레드에서 모든 스레드가 공유하고 있는 "msg" 뮤텍스를 lock 을 하면
	 *     진행되고 있던 철학자들은 "msg" 를 발견하게 되면 blocking 상태에 빠지고,
	 *     더 이상 어떠한 작업을 하고 있지 않은 것 같은 상태가 됩니다.
	 */
	pthread_mutex_lock(&philo->info->msg);
	if (ex == 1)
		printf("%ld ms [%d]%s\n", \
			get_current_time(philo->info->start), philo->id, DIED);
	else
		printf("%ld ms %s\n", \
			get_current_time(philo->info->start), FINISH);
	return (1);
}

/* 메인 스레드가 철학자들을 감시하는 함수 */
int	watch_threads(t_philo *philo)
{
	int				i;
	int				valid;

	while (TRUE)
	{
		i = -1;
		valid = FALSE;
		while (++i < philo->info->nb_philos)
		{
			/* (현재 시간 - 마지막으로 먹었던 시간) >= time_to_die : DIE */
			if (get_current_time(philo[i].last_eat + philo->info->start)
				>= philo->info->time_to_die)
				return (exit_threads(1, &philo[i]));
			pthread_mutex_unlock(&philo->info->msg);
			/* 먹을 횟수가 없는 경우 or 아직 덜 먹은 경우 */
			if (philo->info->number_of_times < 0
				|| philo[i].number_of_times < philo->info->number_of_times)
				valid = TRUE;
		}
		if (!valid)
			return (exit_threads(2, philo));
		pthread_mutex_unlock(&philo->info->msg);
	}
}
