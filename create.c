/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:41 by abastida          #+#    #+#             */
/*   Updated: 2023/07/20 13:03:10 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*pasamos los datos de cada parametro a cada valor*/

int giving_data(t_data *data, char **av)
{
	int i = 0;
	data -> philos_num = ft_atoi(av[1]);
	data -> time_to_die = ft_atoi(av[2]);
	data -> time_to_eat = ft_atoi(av[3]);
	data -> time_sleep = ft_atoi(av[4]);
	if (av[5])
		data -> number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);

	data->fork = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * data->philos_num);
	if (!data->fork)
		return(-1);
	while (i < data->philos_num)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
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
		pthread_mutex_lock(&data->fork[count_threads]);
		if (pthread_create(&threads[count_threads], NULL, &prueba, &philos[count_threads]) != 0)
		{
			printf("Threads can't be created\n");
			return (-1);
		}
		pthread_mutex_unlock(&data->fork[count_threads]);
		count_threads++;
	}
	count_threads = 0;
	while (threads[count_threads])
	{
		pthread_join(threads[count_threads], NULL);
		count_threads++;
	}
	return (0);
}