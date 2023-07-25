#include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	if (philo->num_philo % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(&philo->data->start);
	while(philo->data->someone_died == 0)
	{
		pthread_mutex_unlock(&philo->data->start);
		pthread_mutex_lock(&philo->data->fork[philo->fork_left]);
		printing(1, philo);//ha cogido el tenedor
		pthread_mutex_lock(&philo->data->fork[philo->fork_right]);
		printing(2, philo);
		printing(3, philo);
		ft_sleep(philo->data->time_to_eat);
		pthread_mutex_lock(&philo->data->start);
		philo->last_eat = get_time();
		philo->n_times_has_eat++;
		pthread_mutex_unlock(&philo->data->start);
		pthread_mutex_unlock(&philo->data->fork[philo->fork_left]);
		pthread_mutex_unlock(&philo->data->fork[philo->fork_right]);
		printing(4, philo);
		ft_sleep(philo->data->time_sleep);
		printing(5, philo);
		if (philo->data->number_of_times_each_philosopher_must_eat)
			if (philo->data->number_of_times_each_philosopher_must_eat == philo->n_times_has_eat)
				break ;
	}
	pthread_mutex_unlock(&philo->data->start);
	return(NULL);
}

void *check_philo(void *arg)
{
	int i;
	t_philo  *philo = (t_philo *)arg;
	while (philo->data->someone_died == 0)
	{
		i = 0;
		pthread_mutex_lock(&philo->data->start);
		while (i < philo->data->philos_num)
		{
			if(time_dif(get_time(), philo[i].last_eat) > philo->data->time_to_die)
			{
				pthread_mutex_lock(&philo->data->print);
				philo->data->someone_died = 1;
				printf(BRED"%lld Philo %d has died 💀\n"RESET, (get_time() - philo->data->start_time), (i + 1));
				pthread_mutex_unlock(&philo->data->print);
				break ;
			}
			i++;
		}
		while (--i >= 0 && (philo[i].n_times_has_eat == philo->data->number_of_times_each_philosopher_must_eat) && philo->data->someone_died == 0)
		{
			if (i == 0)
			{
				printing(6, philo);
				pthread_mutex_lock(&philo->data->print);
				philo->data->someone_died = 1;
				pthread_mutex_unlock(&philo->data->print);
				pthread_mutex_unlock(&philo->data->start);
				return (NULL);
			}
		}
		pthread_mutex_unlock(&philo->data->start);
		usleep(100);
	}
	return(NULL);
}

void *if_only_one_philo(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->fork[philo->fork_right]);
	printing(2, philo);
	ft_sleep(philo->data->time_to_die);
	printf("%lld Philo has died\n", (get_time() - philo->data->start_time));
	return (NULL);
	//si solo es un philo coge un tenedor, espera el tiempo (time to die) y muere. 
}
