/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:12:27 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 20:29:39 by abastida         ###   ########.fr       */
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
    while(i++ < data->philos_num)
	{
        philo[i].num_philo = i + 1;
        philo[i].last_eat = 0;
        philo[i].data = data;
    }
    return (philo);
}

int create_philo(t_philo *philo, t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philos_num)
    {
        philo[i].id = fork();
        if (philo[i].id == 0)
                create_one_philo(philo);
        else if (philo[i].id < 0)
            return (-1);
        else 
            printf("hola");
        usleep(50);
    }
    return (0);
}

