/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:50:57 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/23 03:02:05 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_starving(t_dinner *dinner);

void	*death_routine(void *args)
{
	t_dinner	*dinner;

	dinner = (t_dinner *)args;
	while (sim_continues(dinner))
	{
		safe_mutex(&dinner->satisfied_mtx, LOCK);
		if (dinner->satisfied >= dinner->philos_nbr)
		{
			end_sim(dinner);
			safe_mutex(&dinner->satisfied_mtx, UNLOCK);
			break ;
		}
		safe_mutex(&dinner->satisfied_mtx, UNLOCK);
		check_starving(dinner);
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
		safe_mutex(&dinner->last_meal_mtx, LOCK);
		starving = time_since_start(dinner) - dinner->philos[i].last_meal;
		safe_mutex(&dinner->last_meal_mtx, UNLOCK);
		if (starving >= dinner->time_to_die)
		{
			print_action(&dinner->philos[i], DIE);
			end_sim(dinner);
		}
		i++;
	}
}
