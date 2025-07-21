/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:49:26 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	safe_mutex(&philo->dinner->sim_start_mtx, LOCK);
	safe_mutex(&philo->dinner->sim_start_mtx, UNLOCK);
	safe_mutex(&philo->dinner->last_meal_mtx, LOCK);
	philo->last_meal = time_since_start(philo->dinner);
	safe_mutex(&philo->dinner->last_meal_mtx, UNLOCK);
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
	while (sim_continues(dinner))
	{
		i = -1;
		safe_mutex(&dinner->satisfied_mtx, LOCK);
		if (dinner->satisfied == dinner->philos_nbr)
		{
			end_sim(dinner);
			safe_mutex(&dinner->satisfied_mtx, UNLOCK);
		}
		safe_mutex(&dinner->satisfied_mtx, UNLOCK);
		safe_mutex(&dinner->last_meal_mtx, LOCK);
		while (++i < dinner->philos_nbr)
		{
			starving = (time_since_start(dinner) - dinner->philos[i].last_meal);
			if (starving >= dinner->time_to_die)
			{
				print_action(&dinner->philos[i], DIE);
				end_sim(dinner);
			}
		}
		safe_mutex(&dinner->last_meal_mtx, UNLOCK);
		usleep(1000);
	}
	return (NULL);
}
