/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/14 23:08:09 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->full || !philo->dinner->someone_died)
	{
		if (!philo->dinner->someone_died)
			routine_think(philo);
		if (!philo->dinner->someone_died)
			routine_eat(philo);
		if (!philo->dinner->someone_died)
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
	while (i < dinner->philos_nbr)
	{
		starving = (time_since_start(dinner) - dinner->philos[i].last_meal); //TODO: mutex last_meal
		if (starving >= dinner->time_to_die)
		{
			dinner->someone_died = true;
			print_action(&dinner->philos[i], DIE);
			free_dinner(dinner);
			exit (0); //NOTE: temporal
		}
		i++;
		if (i == dinner->philos_nbr)
			i = 0;
	}
	return (args);
}
