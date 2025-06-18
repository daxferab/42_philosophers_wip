/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_members.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:25:42 by daxferna          #+#    #+#             */
/*   Updated: 2025/06/18 13:02:09 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_members(t_dinner *dinner)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	dinner->end = false;
	dinner->philos = malloc(dinner->philos_nbr * sizeof(t_philo));
	if (!dinner->philos)
		return (printf("Malloc failed"), false);
	dinner->forks = malloc(dinner->philos_nbr * sizeof(t_fork));
	if (!dinner->philos)
		return (printf("Malloc failed"), free(dinner->philos), false);
	dinner->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (true);
}
