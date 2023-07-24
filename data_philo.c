/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:25:32 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 16:34:26 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo *create_philo(t_data *data)
{
    t_philo *philo;
    int count = 0;
    philo = (t_philo *)malloc(sizeof(t_philo) * data->philos_num);
    if (!philo)
        return (NULL);
    while(count < data->philos_num)
    {
        philo[count].num_philo = count + 1;
        philo[count].fork_left = count;
        philo[count].fork_right = count + 1;
        if (count + 1 == data->philos_num)
            philo[count].fork_right = 0;
        philo[count].data = data;
        philo[count].last_eat = get_time();
        count ++;
    }
    return (philo);
    /*en esta funcion lo que quiero hacer es darle a cada philo toda la informacion sobre tiempos de cmer, dormir, pensar... */
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
    else
        data -> number_of_times_each_philosopher_must_eat = -1;
	data->fork = (pthread_mutex_t *)malloc (sizeof(pthread_mutex_t) * data->philos_num);
	if (!data->fork)
		return(-1);
	return (init_mutex(data));
}
