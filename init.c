/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:33:51 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 16:19:45 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	data->forks = malloc(data->philo_nbr * sizeof(pthread_mutex_t));
	if (!(data->forks))
		return (1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
		{
			printf("Error: pthread_mutex_init");
			return (1);
		}
	}
	if (pthread_mutex_init(&(data->write), NULL))
	{
		printf("Error: pthread_mutex_init");
		return (1);
	}
	if (pthread_mutex_init(&(data->meal_check), NULL))
	{
		printf("Error: pthread_mutex_init");
		return (1);
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		data->philos[i].nbr = i;
		data->philos[i].philo_ate = 0;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_nbr];
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
	}
	return (0);
}

int	validate_data(t_data *data)
{
	if (data->philo_nbr < 1 || data->time_death < 0 || data->time_eat < 0
		|| data->time_sleep < 0 || data->philo_nbr > 250)
		return (1);
	return (0);
}

int	is_neg(const char *str)
{
	int	value;

	value = ft_atoi(str);
	return (value < 0);
}

int	initialize_data(t_data *data, char **av)
{
	data->philo_nbr = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->all_ate = 0;
	data->died = 0;
	if (validate_data(data))
		printf("Validate data failed");
	if (is_neg(av[1]) || is_neg(av[2]) || is_neg(av[3]) || is_neg(av[4]))
	{
		printf("Error: One or more arguments are negative\n");
		return (1);
	}
	if (av[5])
	{
		data->meal_nbr = ft_atoi(av[5]);
		if (data->meal_nbr <= 0)
			return (1);
	}
	else
		data->meal_nbr = -1;
	if (init_mutex(data))
		return (1);
	init_philos(data);
	return (0);
}
