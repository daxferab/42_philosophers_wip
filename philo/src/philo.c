/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:04:01 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/29 01:12:26 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_param	*parameters;

	if (argc < 5 || argc > 6)
		return(print_error("Wrong number of arguments\n"), 0);
	parameters = malloc(sizeof(t_param));
	if (!parameters)
		return (1);
	if (!init_args(argv, parameters))
		return (free(parameters), 1);
	print_action(2, EAT);
	free(parameters);
	return (0);
}
