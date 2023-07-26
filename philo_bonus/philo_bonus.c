/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:09:10 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 20:14:59 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int main(int ac, char **av)
{
	t_data *data;
	t_philo *philo;

	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (check_errors(ac, av) != 0)
        return (-1);
	if (giving_data(data, av) != 0)
		return (-1);
 	philo = data_philo(data);
	if (!philo)
		return (-1);
	/*if (ft_atoi(av[1]) == 1)
		create_one_philo(philo);*/
	create_philo(philo, data);
				/*	while(i >  )
	{
		if(id != 0)
			fork();
		printf("aprendiendo child and parents\n");
		i++;
	}
*/
	return (0);
}
