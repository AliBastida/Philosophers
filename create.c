/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:41 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 18:05:09 by abastida         ###   ########.fr       */
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
	if(pthread_mutex_init(&data->start, NULL)!= 0)
		return (-1);
	return (0);
}

int create_one_philo(t_philo *philo)
{
	pthread_t the_philo;
	// the_philo = (pthread_t *)malloc(sizeof(pthread_t));
	// if(!the_philo)
		// return (0);
	if (pthread_create(&the_philo, NULL, &if_only_one_philo, philo) != 0)
	{
		printf("Can't create the_philo\n");
		return (-1);
	}
	pthread_join(the_philo, NULL);
	return (0);
}
int create_control(t_philo *philo)
{
	pthread_t control;
	// control = (pthread_t *)malloc(sizeof(pthread_t));
	// if (!control)
		// return (0);
	if (pthread_create(&control, NULL, &check_philo, philo) != 0)
	{
		printf("Can't control if someone died\n");
		return (-1);
	}
	pthread_join(control, NULL);
	// free(control);
	return(0);
}

int ft_create_thread(t_data *data, t_philo *philos) // array philo tambien
{
	pthread_t *threads;
	int count_threads = 0;

	threads = (pthread_t *)malloc(sizeof(pthread_t)* data->philos_num);
	if (!threads)
		return (0);
	pthread_mutex_lock(&data->start);
	while (data->philos_num > count_threads)
	{
		if (pthread_create(&threads[count_threads], NULL, &routine, &philos[count_threads]) != 0)
		{
			printf("Threads can't be created\n");
			return (-1);
		}
		count_threads++;
	
	}
	pthread_mutex_unlock(&data->start);
	create_control(philos);
	count_threads = 0;
	while (threads[count_threads])
	{
		pthread_join(threads[count_threads], NULL);
		count_threads++;
	}
	free(threads);
	return (0);
}

