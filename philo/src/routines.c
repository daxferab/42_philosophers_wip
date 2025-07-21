/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 20:39:05 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
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
	int			i;
	long		starving;

	dinner = (t_dinner *)args;
	while (1)
	{
		i = -1;
		safe_mutex(&dinner->satisfied_mtx, LOCK);
		if (dinner->satisfied == dinner->philos_nbr)
		{
			safe_mutex(&dinner->satisfied_mtx, UNLOCK);
			break ;
		}
		safe_mutex(&dinner->satisfied_mtx, UNLOCK);
		safe_mutex(&dinner->last_meal_mtx, LOCK);
		while (++i < dinner->philos_nbr)
		{
			starving = (time_since_start(dinner) - dinner->philos[i].last_meal);
			if (starving >= dinner->time_to_die)
			{
				print_action(&dinner->philos[i], DIE);
				safe_mutex(&dinner->end_mtx, LOCK);
				dinner->end = true;
				safe_mutex(&dinner->end_mtx, UNLOCK);
				break ;
			}
		}
		safe_mutex(&dinner->last_meal_mtx, UNLOCK);
		usleep(1000);
	}
	return (NULL);
}
