/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/28 04:10:34 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(int philo, char *action)
{
	int	time;

	time = 0; //TODO: gettimeofday (ms)
	printf("%d %d is %s\n", time, philo, action);
}
