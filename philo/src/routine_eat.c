/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:41:46 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/11 19:49:34 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_philo *philo);
static bool	try_eating(t_philo *philo);

void	routine_eat(t_philo *philo)
{
	if (try_eating(philo))
		philo->dinner->someone_died = true;
	print_action(philo, EAT);
	philo->meals++;
	if (philo->meals >= philo->dinner->eating_times
		&& philo->dinner->eating_times != -1)
		philo->full = true;
	philo->last_meal = time_since_start(philo->dinner);
	usleep(philo->dinner->time_to_eat * 1000);
	free_forks(philo);
}

static bool	try_eating(t_philo *philo)
{
	bool	eating;

	eating = false;
	while (!eating)
	{
		if (philo->left_fork->id == philo->right_fork->id)
			return (false);
		pthread_mutex_lock(&philo->left_fork->fork_id);
		pthread_mutex_lock(&philo->right_fork->fork_id);
		if (!philo->left_fork->in_use && !philo->right_fork->in_use)
		{
			philo->left_fork->in_use = true;
			philo->right_fork->in_use = true;
			print_action(philo, FORK);
			print_action(philo, FORK);
			eating = true;
		}
		pthread_mutex_unlock(&philo->left_fork->fork_id);
		pthread_mutex_unlock(&philo->right_fork->fork_id);
	}
	return (true);
}

static void	free_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork_id);
	pthread_mutex_lock(&philo->right_fork->fork_id);
	philo->left_fork->in_use = false;
	philo->right_fork->in_use = false;
	pthread_mutex_unlock(&philo->left_fork->fork_id);
	pthread_mutex_unlock(&philo->right_fork->fork_id);
}
