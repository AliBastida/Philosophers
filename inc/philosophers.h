/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:30 by abastida          #+#    #+#             */
/*   Updated: 2023/07/27 14:48:48 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "colors.h"

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
	int			num_philo;
	int			fork_left;
	int			fork_right;
	int			n_times_has_eat;
	long long	last_eat;
	t_data		*data;
}t_philo;

//philo.c //
int			main(int ac, char **av);

//check_error.c//
int			ft_error(int n);
int			check_errors(int ac, char **av);
int			is_digit(char **av);

//create.c//
int			ft_create_thread(t_data *data, t_philo *philos);
int			init_mutex(t_data *data);
int			create_one_philo(t_data *data, t_philo *philo);

//utils.c//
int			ft_atoi(char *str);

//data_philo.c//
t_philo		*create_philo(t_data *data);
void		*check_philo(void *arg);
void		*if_only_one_philo(void *arg);
int			giving_data(t_data *data, char **av);
//time_control.c//
long long	time_dif(long long current, long long past);
long long	get_time(void);
void		ft_sleep(long long time);

//prueba.c//
void		*routine(void *arg);
void		is_eating(t_philo *philo);
int			check_is_someone_is_dead(t_philo *philo, int i);
void		check_if_everyone_has_eaten(t_philo *philo);

//print.c//
void		printing(int n, t_philo *philo);
void		continue_printing(int n, t_philo *philo);

//free_and_destroy.c
int			free_and_destroy(t_data *data, t_philo *philo, int out);

#endif
