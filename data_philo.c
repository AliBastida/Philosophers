/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:25:32 by abastida          #+#    #+#             */
/*   Updated: 2023/07/23 19:31:49 by abastida         ###   ########.fr       */
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