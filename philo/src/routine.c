/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/04 20:16:01 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*args)
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
