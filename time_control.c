/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:26:40 by abastida          #+#    #+#             */
/*   Updated: 2023/07/24 18:52:24 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	time_dif(long long current, long long past)
{
	return (current - past);
}

/*aqui convertimos el resultado en milisegundos porque
 la struct timeval lo da en segs y en microseg*/
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*tengo que comprobar que funciona correctamente para valores altos*/
void	ft_sleep(long long time)
{
	long long	start;

	start = get_time();
	while (1)
	{
		if (time_dif(get_time(), start) >= time)
			break ;
		usleep(100);
	}
}
