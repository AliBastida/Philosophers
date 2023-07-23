/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:41 by abastida          #+#    #+#             */
/*   Updated: 2023/07/23 19:59:20 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*pasamos los datos de cada parametro a cada valor*/

int init_mutex(t_data *data)
{
	int i = 0;

	while (i < data->philos_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (-1);
		i++;
	}
	if(pthread_mutex_init(&data->print, NULL)!= 0)
		return (-1);
	return (0);
}

int giving_data(t_data *data, char **av)
{
	data -> someone_died = 0;
	data -> start_time = get_time();
	data -> philos_num = ft_atoi(av[1]);
	data -> time_to_die = ft_atoi(av[2]);
	data -> time_to_eat = ft_atoi(av[3]);
	data -> time_sleep = ft_atoi(av[4]);
	if (av[5])
		data -> number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	data->fork = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * data->philos_num);
	if (!data->fork)
		return(-1);
	return (init_mutex(data));
}
int create_control(t_philo *philo)
{
	pthread_t *control;
	control = (pthread_t *)malloc(sizeof(pthread_t));
	if (!control)
		return (0);
	if (pthread_create(control, NULL, &check_philo, philo) != 0)
	{
		printf("Can't control if someone died\n");
		return (-1);
	}
	pthread_join(*control, NULL);
	return(0);
}

int ft_create_thread(t_data *data, t_philo *philos) // array philo tambien
{
	pthread_t *threads;
	int count_threads = 0;

	threads = (pthread_t *)malloc(sizeof(pthread_t)* data->philos_num);
	if (!threads)
		return (0);
	while (data->philos_num > count_threads)
	{
		if (pthread_create(&threads[count_threads], NULL, &routine, &philos[count_threads]) != 0)
		{
			printf("Threads can't be created\n");
			return (-1);
		}
		count_threads++;
	
	}
	create_control(philos);
	count_threads = 0;
	while (threads[count_threads])
	{
		pthread_join(threads[count_threads], NULL);
		count_threads++;
	}
	return (0);
}

