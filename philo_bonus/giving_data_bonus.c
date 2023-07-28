/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giving_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:36:18 by abastida          #+#    #+#             */
/*   Updated: 2023/07/28 17:23:07 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int giving_data(t_data *data, char **av)
{
	data->someone_died = 0;
	data->start_time = get_time();
	data->philos_num = ft_atoi(av[1]);
	
	data->time_to_die= ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if(init_sem(data)!= 0)
		exit(1);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	
	//los tenedores son semaforos;
	//data->fork = semaoforos. 
	return (0);
}
