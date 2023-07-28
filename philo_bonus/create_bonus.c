/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:12:27 by abastida          #+#    #+#             */
/*   Updated: 2023/07/28 18:05:40 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

t_philo *data_philo(t_data *data)
{
    t_philo *philo;
	int i;

    philo = (t_philo *)malloc(sizeof(t_philo) * data->philos_num);
    if(!philo)
        return(NULL); 
    i = 0;
    while(i < data->philos_num)
	{
        philo[i].num_philo = i + 1;
        philo[i].last_eat = 0;
        philo[i].data = data;
        i++;
    }
    return (philo);
}


int init_sem(t_data *data)
{
    sem_unlink("/forks");
    sem_unlink("/start");
    sem_unlink("/print");
    data->fork = sem_open("/forks", O_CREAT, S_IRWXU, data->philos_num);
    data->start = sem_open("/start", O_CREAT, S_IRWXU, 1);
    data->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
    if (data->fork <= 0 || data->print <= 0 || data->start <= 0)
		return (1);
	return (0);
}

int create_philo(t_philo *philo, t_data *data)
{
    
    int i;

    i = -1;
    data->start_time = get_time();
    while (++i < data->philos_num)
    {
        philo[i].pid = fork();
        if (philo[i].pid < 0)
            return (1);
        if (philo[i].pid == 0)
            one_philo(&philo[i]);
        usleep(50);
        printf("yo soy tu padre\n");
    }
    return (0);
}



