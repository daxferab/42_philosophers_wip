/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_members.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:25:42 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/29 16:50:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_members(t_param *param)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	param->end = false;
	param->philos = malloc(param->philos_nbr * sizeof(t_philo));
	if (param->philos == NULL)
		return (print_error("Malloc failed"), false);
	param->forks = malloc(param->philos_nbr * sizeof(t_fork));
	if (param->philos == NULL)
		return (print_error("Malloc failed"), free(param->philos), false);
	param->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (true);
}
