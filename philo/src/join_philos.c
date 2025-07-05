/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:09:36 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/05 02:10:31 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_philos(t_dinner *dinner)
{
	int		i;

	i = 0;
	while (i < dinner->philos_nbr)
	{
		if (pthread_join(dinner->philos[i].thread_id, NULL))
			return (false);
		i++;
	}
	pthread_join(dinner->watcher, NULL);
	return (true);
}
