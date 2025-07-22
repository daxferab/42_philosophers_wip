/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:26:59 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/22 21:08:17 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo(t_philo *philo);

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	safe_mutex(&philo->dinner->sim_start_mtx, LOCK);
	safe_mutex(&philo->dinner->sim_start_mtx, UNLOCK);
	safe_mutex(&philo->dinner->last_meal_mtx, LOCK);
	philo->last_meal = philo->dinner->start_time;
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

static void	*one_philo(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork_id, LOCK);
	print_action(philo, FORK);
	safe_usleep(philo, philo->dinner->time_to_die);
	safe_mutex(&philo->left_fork->fork_id, UNLOCK);
	return (NULL);
}
