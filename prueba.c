#include "philosophers.h"

void *routine()
{
	printf("test\n");
	sleep(2);
	return (0);
}

void *prueba(void *arg)
{
	t_philo *philo = (t_data *)arg;
	printf("otra prueba\n");
	sleep(2);
	return (0);
}
