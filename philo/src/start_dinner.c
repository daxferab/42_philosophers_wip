/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:34:28 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/15 14:49:25 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_forks(t_dinner *dinner);
static bool	init_philos(t_dinner *dinner);
static void	assign_forks(t_dinner *dinner, int i);

bool	start_dinner(t_dinner *dinner)
{
	if (pthread_mutex_init(&dinner->print, NULL))
		return (false);
	if (!init_forks(dinner))
		return (false);
	dinner->start_time = time_since_start(NULL);
	if (!init_philos(dinner))
		return (false);
	if (pthread_create(&dinner->death, NULL, death_routine, dinner))
		return (false);
	return (true);
}

static bool	init_forks(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->forks = malloc(sizeof(t_fork) * dinner->philos_nbr);
	while (i < dinner->philos_nbr)
	{
		dinner->forks[i].id = i;
		dinner->forks[i].in_use = false;
		if (pthread_mutex_init(&dinner->forks[i].fork_id, NULL))
			return (false);
		i++;
	}
	return (true);
}

static bool	init_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	dinner->philos = malloc(sizeof(t_philo) * dinner->philos_nbr);
	while (i < dinner->philos_nbr)
	{
		dinner->philos[i].id = i + 1;
		dinner->philos[i].meals = 0;
		dinner->philos[i].full = false;
		dinner->philos[i].last_meal = dinner->start_time;
		dinner->philos[i].dinner = dinner;
		assign_forks(dinner, i);
		if (pthread_create(&dinner->philos[i].thread_id, NULL, philo_routine,
				&(dinner->philos[i])))
			return (false);
		i++;
	}
	return (true);
}

static void	assign_forks(t_dinner *dinner, int i)
{
	int	n_philos;

	n_philos = dinner->philos_nbr;
	if (i < dinner->philos_nbr - 1)
	{
		dinner->philos[i].left_fork = &(dinner->forks[i]);
		dinner->philos[i].right_fork = &(dinner->forks[(i + 1) % n_philos]);
	}
	else
	{
		dinner->philos[i].right_fork = &(dinner->forks[i]);
		dinner->philos[i].left_fork = &(dinner->forks[(i + 1) % n_philos]);
	}
}
