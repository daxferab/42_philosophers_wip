/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/22 02:02:17 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_starving(t_dinner *dinner);

void	*one_philo(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork_id, LOCK);
	print_action(philo, FORK);
	safe_usleep(philo, philo->dinner->time_to_die);
	safe_mutex(&philo->left_fork->fork_id, UNLOCK);
	return (NULL);
}

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	safe_mutex(&philo->dinner->sim_start_mtx, LOCK);
	safe_mutex(&philo->dinner->sim_start_mtx, UNLOCK);
	safe_mutex(&philo->dinner->last_meal_mtx, LOCK);
	philo->last_meal = time_since_start(philo->dinner);
	safe_mutex(&philo->dinner->last_meal_mtx, UNLOCK);
	if (philo->dinner->philos_nbr == 1)
		return (one_philo(philo));
	while (sim_continues(philo->dinner))
	{
		routine_think(philo);
		routine_eat(philo);
		routine_sleep(philo);
	}
	return (args);
}

void	*death_routine(void *args)
{
	t_dinner	*dinner;

	dinner = (t_dinner *)args;
	while (sim_continues(dinner))
	{
		safe_mutex(&dinner->satisfied_mtx, LOCK);
		if (dinner->satisfied == dinner->philos_nbr)
		{
			end_sim(dinner);
			safe_mutex(&dinner->satisfied_mtx, UNLOCK);
			break ;
		}
		safe_mutex(&dinner->satisfied_mtx, UNLOCK);
		safe_mutex(&dinner->last_meal_mtx, LOCK);
		check_starving(dinner);
		safe_mutex(&dinner->last_meal_mtx, UNLOCK);
		usleep(1000);
	}
	return (NULL);
}

static void	check_starving(t_dinner *dinner)
{
	int		i;
	long	starving;

	i = 0;
	while (i < dinner->philos_nbr)
	{
		starving = (time_since_start(dinner) - dinner->philos[i].last_meal);
		if (starving >= dinner->time_to_die)
		{
			print_action(&dinner->philos[i], DIE);
			end_sim(dinner);
		}
		i++;
	}
}
