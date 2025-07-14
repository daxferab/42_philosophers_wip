/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/10 17:58:29 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	print_action(t_philo *philo, char *action)
{
	long			time;

	pthread_mutex_lock(&philo->dinner->print);
	time = time_since_start(philo->dinner);
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->dinner->print);
}
