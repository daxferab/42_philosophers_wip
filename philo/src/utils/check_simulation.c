/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:29:41 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/22 21:29:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sim_continues(t_dinner *dinner)
{
	bool	ret_value;

	safe_mutex(&dinner->end_mtx, LOCK);
	ret_value = dinner->end;
	safe_mutex(&dinner->end_mtx, UNLOCK);
	return (!ret_value);
}

void	end_sim(t_dinner *dinner)
{
	safe_mutex(&dinner->end_mtx, LOCK);
	dinner->end = true;
	safe_mutex(&dinner->end_mtx, UNLOCK);
}
