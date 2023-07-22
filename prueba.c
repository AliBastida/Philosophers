#include "philosophers.h"

void *routine()
{
	printf("test\n");
	sleep(2);
	return (0);
}

void *prueba(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	printf("philo %d\n", philo->num_philo);
	printf("fork_left %d\n", philo->fork_left);
	printf("fork_right %d\n", philo->fork_right);
	sleep(1);
	return (0);
}
