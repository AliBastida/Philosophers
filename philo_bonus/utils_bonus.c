/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:44:40 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 17:30:16 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philobonus.h"

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}
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
