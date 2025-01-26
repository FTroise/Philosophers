/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:58:55 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 17:59:01 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	g_fork(t_philo *philo, pthread_mutex_t *tlf, pthread_mutex_t *trf)
{
	pthread_mutex_lock(tlf);
	pthread_mutex_lock(trf);
	w_message(philo->data, philo->nbr, "Has taken a fork");
}

void	eat(t_philo *philo)
{
	t_data				*data;
	pthread_mutex_t		*tmp_l_fork;
	pthread_mutex_t		*tmp_r_fork;

	data = philo->data;
	tmp_l_fork = NULL;
	tmp_r_fork = NULL;
	if (philo->nbr % 2 == 0)
	{
		tmp_l_fork = philo->l_fork;
		tmp_r_fork = philo->r_fork;
	}
	else
	{
		tmp_l_fork = philo->r_fork;
		tmp_r_fork = philo->l_fork;
	}
	g_fork(philo, tmp_l_fork, tmp_r_fork);
	w_message(data, philo->nbr, "is eating");
	philo->last_meal = get_time();
	ft_sleep(data->time_eat, data);
	(philo->philo_ate)++;
	pthread_mutex_unlock(tmp_l_fork);
	pthread_mutex_unlock(tmp_r_fork);
}

void	*action(void *void_argv)
{
	int		i;
	t_philo	*phi;
	t_data	*data;

	i = 0;
	phi = (t_philo *)void_argv;
	data = phi->data;
	if (phi->nbr % 2)
		usleep(100);
	while (!(data->died))
	{
		eat(phi);
		if (data->all_ate)
			break ;
		w_message(data, phi->nbr, "is sleeping");
		ft_sleep(data->time_sleep, data);
		w_message(data, phi->nbr, "is thinking");
		i++;
	}
	return (NULL);
}

void	quit(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_nbr)
		pthread_join(philos[i].thread_nbr, NULL);
	i = -1;
	while (++i < data->philo_nbr)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write));
}

void	check_single_philo_death(t_data *p, t_philo *phi, int i)
{
	pthread_mutex_lock(&(p->meal_check));
	if (time_delta(phi[i].last_meal, get_time()) > p->time_death)
	{
		w_message(p, i, "died");
		p->died = 1;
		exit(1);
	}
	pthread_mutex_unlock(&(p->meal_check));
}
