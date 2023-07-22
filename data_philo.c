/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:25:32 by abastida          #+#    #+#             */
/*   Updated: 2023/07/22 11:02:30 by abastida         ###   ########.fr       */
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
        pthread_mutex_lock(&data->fork[count]);
        philo[count].num_philo = count;
        philo[count].fork_left = count - 1;
        if (count == 0)
            philo[0].fork_left = data->philos_num - 1;
        philo[count].fork_right = count;
        philo[count].data = philo->data;
        pthread_mutex_unlock(&data->fork[count]);
        count ++;   
    }
    return (philo);
    /*en esta funcion lo que quiero hacer es darle a cada philo toda la informacion sobre tiempos de cmer, dormir, pensar... */
}