/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:41:46 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:09:46 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_sleep(t_philo *philo)
{
	print_action(philo, SLEEP);
	safe_usleep(philo, philo->dinner->time_to_sleep);
}
