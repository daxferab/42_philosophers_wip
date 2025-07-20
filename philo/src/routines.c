/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/20 14:46:38 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_philos_status(t_dinner *dinner);

void	*philo_routine(void *args)
{
	t_philo	*philo;
	bool	should_stop;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->dinner->death_mutex);
		should_stop = philo->dinner->someone_died || philo->dinner->all_full;
		pthread_mutex_unlock(&philo->dinner->death_mutex);
		if (should_stop)
			break ;
		routine_think(philo);
		routine_eat(philo);
		routine_sleep(philo);
	}
	return (args);
}

void	*death_routine(void *args)
{
	t_dinner	*dinner;
	int			i;
	long		starving;

	dinner = (t_dinner *)args;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&dinner->death_mutex);
		if (dinner->all_full || dinner->someone_died)
		{
			pthread_mutex_unlock(&dinner->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&dinner->death_mutex);
		pthread_mutex_lock(&dinner->philos[i].philo_mutex);
		starving = (time_since_start(dinner) - dinner->philos[i].last_meal);
		pthread_mutex_unlock(&dinner->philos[i].philo_mutex);
		if (starving >= dinner->time_to_die)
		{
			print_action(&dinner->philos[i], DIE);
			pthread_mutex_lock(&dinner->death_mutex);
			dinner->someone_died = true;
			pthread_mutex_unlock(&dinner->death_mutex);
			break ;
		}
		if (check_philos_status(dinner))
			break ;
		i = (i + 1) % dinner->philos_nbr;
		usleep(1000);
	}
	return (NULL);
}

static bool	check_philos_status(t_dinner *dinner)
{
	int		i;
	bool	all_full;

	all_full = true;
	i = 0;
	while (i < dinner->philos_nbr)
	{
		pthread_mutex_lock(&dinner->philos[i].philo_mutex);
		if (!dinner->philos[i].full)
			all_full = false;
		pthread_mutex_unlock(&dinner->philos[i].philo_mutex);
		if (!all_full)
			break ;
		i++;
	}
	pthread_mutex_lock(&dinner->death_mutex);
	if (all_full && dinner->eating_times != -1)
		dinner->all_full = true;
	pthread_mutex_unlock(&dinner->death_mutex);
	return (all_full && dinner->eating_times != -1);
}
