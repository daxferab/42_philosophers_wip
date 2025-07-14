/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:41:46 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/10 17:43:12 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	usleep(philo->dinner->time_to_sleep * 1000);
}
