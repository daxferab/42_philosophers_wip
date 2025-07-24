/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:13:10 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/24 10:19:15 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_dinner(t_dinner *dinner, bool destroy)
{
	int	i;

	i = 0;
	if (destroy)
	{
		safe_mutex(&dinner->sim_start_mtx, DESTROY);
		safe_mutex(&dinner->end_mtx, DESTROY);
		safe_mutex(&dinner->satisfied_mtx, DESTROY);
		safe_mutex(&dinner->last_meal_mtx, DESTROY);
		safe_mutex(&dinner->print_mtx, DESTROY);
		while (i < dinner->philos_nbr)
		{
			safe_mutex(&dinner->philos[i].right_fork->fork_id, DESTROY);
			i++;
		}
	}
	if (dinner->philos)
		free(dinner->philos);
	if (dinner->forks)
		free(dinner->forks);
	free(dinner);
}
