/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/05 01:33:22 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, long start, char *action)
{
	long			time;

	pthread_mutex_lock(&philo->dinner->print);
	time = get_time() - start;
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->dinner->print);
}
