#include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	if (philo->num_philo % 2 == 0)
		usleep(500);
	while(philo->data->someone_died == 0)
	{
		if (philo->data->number_of_times_each_philosopher_must_eat)
			{
				if (philo->data->number_of_times_each_philosopher_must_eat == philo->n_times_has_eat)
					break ;
			}
		pthread_mutex_lock(&philo->data->fork[philo->fork_left]);
		printing(1, philo);//ha cogido el tenedor
		pthread_mutex_lock(&philo->data->fork[philo->fork_right]);
		printing(2, philo);
		philo->last_eat = get_time();
		printing(3, philo);
		philo->n_times_has_eat++;
		ft_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->fork[philo->fork_left]);
		pthread_mutex_unlock(&philo->data->fork[philo->fork_right]);
		printing(4, philo);
		ft_sleep(philo->data->time_sleep);
		printing(5, philo);
	}
	
	return(NULL);
}

void *check_philo(void *arg)
{
	int i;
	t_philo  *philo = (t_philo *)arg;
	while(philo->data->someone_died == 0)
	{
		i = 0;
		while(i < philo->data->philos_num)
		{
			if(time_dif(get_time(), philo[i].last_eat) > philo->data->time_to_die)
			{
				philo->data->someone_died = 1;
				printf("someone has died: Philo %d\n", i + 1);
				break ;
			}
			i++;
		}
		//si exite number_of_times_each_philosopher_must_eat tengo que comprobar qe todos han comido ese numero de veces. tengo que iterar en toodos los philos. dos condiciones, i >= 0 && philo[i]-> n_times_has_eat == number_of_times_each_philosopher_must_eat i--. si i = 0, es porque todos han comido.//
	}
	return(NULL);
	/*falta free y destroy de todo. */
}
