/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:02 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 17:58:40 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# define COLOR_RESET "\x1b[0m"
# define COLOR_GREEN "\x1b[32m"

typedef struct s_philo
{
	int				nbr;
	int				philo_ate;
	long long		last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	struct s_data	*data;
	pthread_t		thread_nbr;
}	t_philo;

typedef struct s_data
{
	int				eat;
	long long		first_time;
	int				philo_nbr;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				meal_nbr;
	int				died;
	int				all_ate;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	t_philo			philos[250];
}	t_data;

int			init_mutex(t_data *data);
int			init_philos(t_data *data);
int			initialize_data(t_data *data, char **av);
void		eat(t_philo *philo);
void		g_fork(t_philo *philo, pthread_mutex_t *tlf, pthread_mutex_t *trf);
void		*action(void *void_argv);
void		quit(t_data *data, t_philo *philos);
void		check_death(t_data *p, t_philo *phi);
int			thread(t_data *data);
int			ft_atoi(const char *s);
int			validate_data(t_data *data);
long long	get_time(void);
void		ft_sleep(long long duration, t_data *data);
void		w_message(t_data *data, int nbr, char *str);
long long	time_delta(long long past, long long pres);
void		check_single_philo_death(t_data *p, t_philo *phi, int i);
int			check_all_philos_ate(t_data *p, t_philo *phi);
#endif
