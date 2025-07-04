/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:41:46 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/04 20:56:51 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_eat(t_philo *philo)
{
	bool	eating;

	eating = false;
	while (!eating)
	{
		if (philo->left_fork->id == philo->right_fork->id) //TODO: Gestionar
			continue ;
		pthread_mutex_lock(&philo->left_fork->fork_id);
		pthread_mutex_lock(&philo->right_fork->fork_id);
		if (!philo->left_fork->in_use && !philo->right_fork->in_use)
		{
			philo->left_fork->in_use = true;
			philo->right_fork->in_use = true;
			print_action(philo, philo->dinner->start_time, FORK);
			print_action(philo, philo->dinner->start_time, FORK);
			eating = true;
		}
		pthread_mutex_unlock(&philo->left_fork->fork_id);
		pthread_mutex_unlock(&philo->right_fork->fork_id);
	}
	print_action(philo, philo->dinner->start_time, EAT);
	philo->meals++;
	if (philo->meals >= philo->dinner->eating_times && philo->dinner->eating_times != -1)
		philo->full = true;
	philo->last_meal = get_time() - philo->dinner->start_time;
	usleep(philo->dinner->time_to_eat * 1000);
	pthread_mutex_lock(&philo->left_fork->fork_id);
	pthread_mutex_lock(&philo->right_fork->fork_id);
	philo->left_fork->in_use = false;
	philo->right_fork->in_use = false;
	pthread_mutex_unlock(&philo->left_fork->fork_id);
	pthread_mutex_unlock(&philo->right_fork->fork_id);
}
