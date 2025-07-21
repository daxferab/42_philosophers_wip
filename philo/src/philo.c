/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:04:01 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/21 21:57:05 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_dinner	*dinner;

	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 0);
	dinner = malloc(sizeof(t_dinner));
	if (!dinner)
		return (printf("Internal error\n"), 1);
	if (!init_params(argv, dinner))
		return (free(dinner), 1);
	if (!start_dinner(dinner))
		return (free_dinner(dinner, true), 1);
	join_philos(dinner);
	free_dinner(dinner, true);
	return (0);
}
