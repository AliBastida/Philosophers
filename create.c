/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:40:41 by abastida          #+#    #+#             */
/*   Updated: 2023/07/04 09:56:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*pasamos los datos de cada parametro a cada valor*/

int giving_data(t_data *data, char **av)
{
	data -> philos_num = ft_atoi(av[1]);
	data -> time_to_die = ft_atoi(av[2]);
	data -> time_to_eat = ft_atoi(av[3]);
	data -> time_sleep = ft_atoi(av[4]);
	if (av[5])
		data -> number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	return (0);
}

int ft_create_thread(t_data *data)
{
	pthread_t *threads;
	int count_threads = 0;

	threads = (pthread_t *)malloc(sizeof(pthread_t)* data->philos_num);
	if (!threads)
		return (0);
	while (data->philos_num > count_threads)
	{
		if (pthread_create(&threads[count_threads], NULL, &prueba, NULL) != 0)
		{
			printf("Threads can't be created\n");
			return (-1);
		}
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