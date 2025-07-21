/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:40:22 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	long	time;

	safe_mutex(&philo->dinner->print_mtx, LOCK);
	time = time_since_start(philo->dinner);
	if (!sim_continues(philo->dinner))
	{
		safe_mutex(&philo->dinner->print_mtx, UNLOCK);
		return ;
	}
	printf("%ld %d %s\n", time, philo->id, action);
	// if (ft_strncmp(action, DIE, 4) != 0)
	// {
	safe_mutex(&philo->dinner->print_mtx, UNLOCK);
	// }
}
