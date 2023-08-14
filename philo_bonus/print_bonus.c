/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:36:16 by abastida          #+#    #+#             */
/*   Updated: 2023/08/14 15:05:50 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

void	printing(int n, t_philo *philo)
{
	if (philo->data->someone_died == 0)
	{
	sem_wait(philo->data->print);
		return ;
	}
	if (n == 1)
	{
		printf("%lld %d has taken left fork 🍴 \n", (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 2)
	{
		printf("%lld %d has taken right fork 🍴 \n", (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 3)
	{
		printf(YEL"%lld %d is eating 🥗\n"RESET, (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	sem_post(philo->data->print);
	continue_printing(n, philo);
}

void	continue_printing(int n, t_philo *philo)
{
	sem_wait(philo-> data-> print);
	if (philo-> data-> someone_died == 0)
	{
		sem_post(philo-> data-> print);
		return ;
	}
	if (n == 4)
	{
		printf(BLU"%lld %d is sleeping 💤\n"RESET, (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 5)
	{
		printf(CYN"%lld %d is thinking 💭\n"RESET, (get_time() - 
				philo-> data->start_time), philo->num_philo);
	}
	else if (n == 6)
		printf(MAG"Everyone has eaten enough! 🥣 \n"RESET);
	sem_post(philo->data->print);
}