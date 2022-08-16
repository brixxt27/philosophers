#include "../inc/philosophers.h"

/* 반환 값 = (현재 current_time 시간 - 매개변수 start 시간)  */
long	get_current_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - start);
}

/* 철학자가 식사하는 함수 */
void	philo_eating(t_philo *philo)
{
	struct timeval	current_time;
	long			start;

	pthread_mutex_lock(philo->right);
	/* 
	 * "msg" lock 을 하는 이유?
	 *  => printf 는 buffer management로 이뤄진 함수이다.
	 *     예를 들어 1번째 철학자가 오른쪽 포크를 들고 바로 printf 를 띄운다고 가정
     *     그 때 버퍼에 "%ld ms [" 까지 버퍼링 되다가 3번째 철학자가 오른쪽 포크를 들고 printf 수행
	 *     즉, context switch 가 일어나서 buffer 라는 자원이 망가지는 현상 발생
	 */
	pthread_mutex_lock(&philo->info->msg);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, R_FRK);
	pthread_mutex_unlock(&philo->info->msg);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->info->msg);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, L_FRK);
	printf("%ld ms [%d]%s\n", \
		get_current_time(philo->info->start), philo->id, EAT);
	pthread_mutex_unlock(&philo->info->msg);
	gettimeofday(&current_time, NULL);
	start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	/*
	 * 철학자 스레드는 0.2 ms 만큼 잠들다 깨어나면 조건을 확인하는 식으로 진행
	 * 굳이 usleep(200) 을 한 이유는 뭘까요?
	 * => while (...) ; 으로 무한루프를 돌릴 수 있습니다.
	 *    그러나, while (...) ; 는 스레드가 해당 무한루프를 계속 수행하는 overhead 가 존재합니다.
	 *    즉, 철학자 스레드는 cpu cycle 을 계속해서 잡아먹습니다.
	 * 따라서 usleep(200) 을 통해 잠깐 스레드는 잠들다가 0.2 ms 가 지나면 깨어나서 수행하도록 합니다.
	 * 즉, cpu cycle 을 적게 잡아먹도록 하여 cpu 의 utilization 을 조금이라도 올리기 위함이죠 ^^ 
	 */
	while (get_current_time(start) < philo->info->time_to_eat)
		usleep(200);
	philo->last_eat = get_current_time(philo->info->start);
	if (philo->info->number_of_times > 0)
		philo->number_of_times++;
	/* 
	 * 아까 평가때 1 번째 철학자는 유일하게 8 번 먹었다고 나왔습니다.
	 * philo->number_of_times 값이 number_of_times 과 동일할 때 따로 처리가 없습니다.
	 * 따라서 1 번째 철학자는 8 개가 나오게 됩니다.
	 * 좀 더 설명드리면 (1, 3) => (2, 4) => ... => (5, 1) 이 상황을 고려해볼게요.
	 * 마지막에 5 번째 철학자와 1 번째 철학자가 포크를 동시에 포크를 들다가 종료된 상태입니다.
	 * 이때, 1 번째 철학자가 이전에 7번 먹었을 경우, 5, 1 번째 철학자가 포크를 동시에 들게 되면,
	 * 5 번째 철학자는 7번, 1 번째 철학자는 8번을 먹고 종료되는 거죠 ^^
	 */
}

/* 철학자의 일과...? */
void	*philo_routin(void *p)
{
	t_philo			*philo;
	struct timeval	current_time;
	long			start;

	philo = (t_philo *)p;
	while (TRUE)
	{
		philo_eating(philo);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_lock(&philo->info->msg);
		printf("%ld ms [%d]%s\n", \
			get_current_time(philo->info->start), philo->id, SLP);
		pthread_mutex_unlock(&philo->info->msg);
		gettimeofday(&current_time, NULL);
		start = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
		while (get_current_time(start) < philo->info->time_to_sleep)
			usleep(100);
		pthread_mutex_lock(&philo->info->msg);
		printf("%ld ms [%d]%s\n", \
			get_current_time(philo->info->start), philo->id, THNK);
		pthread_mutex_unlock(&philo->info->msg);
	}
	return (0);
}

void	clear_mutex(t_glob *info, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_mutex_destroy(&(info->forks[i]));
	pthread_mutex_destroy(&(info->msg));
}
