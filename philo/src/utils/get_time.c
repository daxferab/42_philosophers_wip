/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:27:27 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/23 17:34:30 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_dinner *dinner)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (dinner)
		return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - dinner->start_time);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
