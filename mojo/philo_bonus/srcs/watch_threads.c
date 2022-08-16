#include "../inc/philosophers.h"

/* 자식 프로세스의 main 스레드가 philo 스레드를 모니터링하는 함수 */
void	watch_thread(t_philo *philo)
{
	while (TRUE)
	{
		/* msg 를 sem_wait 하는 이유는 Mandatory 와 동일합니다. */
		sem_wait(philo->info->msg);
		if (get_current_time(philo->last_eat + philo->info->start)
			>= philo->info->time_to_die)
		{
			printf("%ld ms [%d]%s\n", \
				get_current_time(philo->info->start), philo->id, DIED);
			exit(1);
		}
		sem_post(philo->info->msg);
		if (philo->info->number_of_times > 0
			&& philo->number_of_times >= philo->info->number_of_times)
			exit(2);
	}
}

/* 부모(main) 프로세스가 자식 프로세스들을 모니터링하는 함수 */
int	watch_prosses(t_philo *philo)
{
	int				i;
	int				status;

	while (TRUE)
	{
		/* 최초로 자식 프로세스가 종료된 상태(특정 철학자가 종료) */
		if (waitpid(-1, &status, 0))
		{
			/* 철학자가 죽은 경우 (status = 256 * (exit 인자값)) */
			if (status == 256)
			{
				i = -1;
				/* 모든 철학자들에게 SIGINT 시그널을 보냅니다. (전부 죽음) */
				while (++i < philo->info->nb_philos)
					kill(philo[i].pid, SIGINT);
				return (0);
			}
			/* 철학자가 다 먹은 경우 (status = 256 * (exit 인자값)) */
			else if (status == 512)
			{
				i = 0;
				/* (n - 1) 명의 철학자를 대기합니다. */
				while (++i < philo->info->nb_philos)
					waitpid(-1, NULL, 0);
				/* 모든 대기가 끝나면 FINISH 를 출력하고 종료 */
				printf("%ld ms %s\n", \
					get_current_time(philo->info->start), FINISH);
				return (0);
			}
		}
	}
}
