/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:33:03 by ftroise           #+#    #+#             */
/*   Updated: 2024/02/25 16:06:29 by ftroise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - 48;
		s++;
	}
	return (value * sign);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday (&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_delta(long long past, long long pres)
{
	return (pres - past);
}

void	ft_sleep(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	while (!(data->died))
	{
		if (time_delta(i, get_time()) >= time)
			break ;
		usleep(1);
	}
}

void	w_message(t_data *data, int nbr, char *str)
{
	pthread_mutex_lock(&(data->write));
	if (!(data->died))
	{
		printf("%lli ", get_time() - data->first_time);
		printf("%i ", nbr + 1);
		printf("%s%s%s\n", COLOR_GREEN, str, COLOR_RESET);
	}
	pthread_mutex_unlock(&(data->write));
	return ;
}
