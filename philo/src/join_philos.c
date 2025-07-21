/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:09:36 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 19:03:02 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	while (i < dinner->philos_nbr)
	{
		safe_thread(&dinner->philos[i].thread_id, JOIN, NULL, NULL);
		i++;
	}
	safe_thread(&dinner->death, JOIN, NULL, NULL);
	return (true);
}
