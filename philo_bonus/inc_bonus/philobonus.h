/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philobonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:33 by abastida          #+#    #+#             */
/*   Updated: 2023/07/26 20:12:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOBONUS_H
# define PHILOBONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include "colors_bonus.h"

typedef struct s_data
{
	int				philos_num;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
	int				time_to_eat;
	int				time_to_die;
	int				time_sleep;
	int				must_eat;
	int				someone_died;
	long long		start_time;
}t_data;

typedef struct s_philo
{
	int			id;
	int			num_philo;
	int			fork_left;
	int			fork_right;
	int			n_times_has_eat;
	long long	last_eat;
	t_data		*data;
}t_philo;


//philo_bonus.c
int 		main(int ac, char **av);

//check_error_bonus.c
int			ft_error(int n);
int			check_errors(int ac, char **av);
int			is_digit(char **av);

//utils_bonus.c
int			ft_atoi(char *str);
long long	time_dif(long long current, long long past);
long long	get_time(void);
void		ft_sleep(long long time);

//giving_data_bonus.c
int 		giving_data(t_data *data, char **av);

//create_bonus.c
t_philo *data_philo(t_data *data);
int create_philo(t_philo *philo, t_data *data);

//print.c
void	printing(int n, t_philo *philo);
void	continue_printing(int n, t_philo *philo);

//routine.c
void *one_philo(void *arg);
int	create_one_philo(t_philo *philo);

#endif
