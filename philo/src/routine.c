/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/05 14:05:40 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->full)
	{
		routine_think(philo);
		routine_eat(philo);
		routine_sleep(philo);
	}
	return(args);
}

void	*death_routine(void *args)
{
	t_dinner	*dinner;

	dinner = (t_dinner *)args;
	while (true)
		if (dinner->someone_died)
			break ;
	return(args);
}
