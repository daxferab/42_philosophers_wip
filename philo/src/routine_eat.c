/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:41:46 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:33:21 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_philo *philo);
static bool	try_eating(t_philo *philo);

void	routine_eat(t_philo *philo)
{
	if (!try_eating(philo))
	{
		usleep(philo->dinner->time_to_die * 1000);
		print_action(&philo[0], DIE);
		free_dinner(philo->dinner);
		exit (0);
	}
	if (sim_continues(philo->dinner))
		philo->meals++;
	print_action(philo, EAT);
	safe_mutex(&philo->dinner->satisfied_mtx, LOCK);
	if (philo->meals >= philo->dinner->eating_times
		&& philo->dinner->eating_times != -1)
		philo->dinner->satisfied++;
	safe_mutex(&philo->dinner->satisfied_mtx, UNLOCK);
	safe_mutex(&philo->dinner->last_meal_mtx, LOCK);
	philo->last_meal = time_since_start(philo->dinner);
	safe_mutex(&philo->dinner->last_meal_mtx, UNLOCK);
	safe_usleep(philo, philo->dinner->time_to_eat);
	free_forks(philo);
}

static bool	try_eating(t_philo *philo)
{
	bool	eating;

	eating = false;
	if (philo->left_fork->id == philo->right_fork->id)
		return (false);
	while (!eating)
	{
		safe_mutex(&philo->left_fork->fork_id, LOCK);
		safe_mutex(&philo->right_fork->fork_id, LOCK);
		if (!philo->left_fork->in_use && !philo->right_fork->in_use)
		{
			philo->left_fork->in_use = true;
			philo->right_fork->in_use = true;
			print_action(philo, FORK);
			print_action(philo, FORK);
			eating = true;
		}
		safe_mutex(&philo->left_fork->fork_id, UNLOCK);
		safe_mutex(&philo->right_fork->fork_id, UNLOCK);
	}
	return (true);
}

static void	free_forks(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork_id, LOCK);
	safe_mutex(&philo->right_fork->fork_id, LOCK);
	philo->left_fork->in_use = false;
	philo->right_fork->in_use = false;
	safe_mutex(&philo->left_fork->fork_id, UNLOCK);
	safe_mutex(&philo->right_fork->fork_id, UNLOCK);
}
