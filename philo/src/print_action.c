/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:00:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/22 02:25:39 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_format();

void	print_action(t_philo *philo, char *action)
{
	long	time;

	safe_mutex(&philo->dinner->print_mtx, LOCK);
	time = time_since_start(philo->dinner);
	if (!sim_continues(philo->dinner))
	{
		safe_mutex(&philo->dinner->print_mtx, UNLOCK);
		return ;
	}
	print_format(time, philo->id, action);
	safe_mutex(&philo->dinner->print_mtx, UNLOCK);
}

static void	print_format(long time, int	id, char *action)
{
	printf("\033[1m%ld\033[0m ", time);
	printf("%d ", id);
	if (ft_strncmp(action, EAT, 10) == 0)
		printf("\033[38;5;46m%s\033[0m\n", action);
	else if (ft_strncmp(action, SLEEP, 11) == 0)
		printf("\033[38;5;21m%s\033[0m\n", action);
	else if (ft_strncmp(action, THINK, 11) == 0)
		printf("\033[38;5;39m%s\033[0m\n", action);
	else if (ft_strncmp(action, DIE, 4) == 0)
		printf("\033[38;5;196m%s\033[0m\n", action);
	else if (ft_strncmp(action, FORK, 17) == 0)
		printf("\033[38;5;226m%s\033[0m\n", action);
}
