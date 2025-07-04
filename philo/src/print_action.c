/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/04 18:59:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, long start, char *action)
{
	long			time;
	struct timeval	tv;

	pthread_mutex_lock(&philo->dinner->print);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start;
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->dinner->print);
}
