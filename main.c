/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:33:19 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 16:13:39 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *p, t_philo *phi)
{
	int	i;

	while (!(p->all_ate) && !(p->died))
	{
		i = -1;
		while (++i < p->philo_nbr)
		{
			check_single_philo_death(p, phi, i);
			usleep(p->time_eat + p->time_sleep);
		}
		if (p->died)
			break ;
		if (check_all_philos_ate(p, phi))
			p->all_ate = 1;
	}
}

int	check_all_philos_ate(t_data *p, t_philo *phi)
{
	int	i;

	i = 0;
	while (p->meal_nbr != -1 && i < p->philo_nbr
		&& phi[i].philo_ate >= p->meal_nbr)
		i++;
	return (i == p->philo_nbr);
}

int	thread(t_data *data)
{
	t_philo	*filos;
	int		i;

	i = 0;
	filos = data->philos;
	data->first_time = get_time();
	while (i < data->philo_nbr)
	{
		if (pthread_create(&filos[i].thread_nbr, NULL,
				action, &(filos[i])))
			return (1);
		filos[i].last_meal = get_time();
		i++;
	}
	check_death(data, data->philos);
	quit(data, filos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		check;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong arguments!\n");
		return (1);
	}
	check = initialize_data(&data, argv);
	if (check)
	{
		printf("One or More args!\n");
		return (1);
	}
	if (thread(&data))
	{
		printf("Failed to create the threads\n");
		return (1);
	}
	return (0);
}
