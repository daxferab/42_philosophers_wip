/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:34:28 by daxferna          #+#    #+#             */
/*   Updated: 2025/04/29 16:42:30 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *n);
static bool	ft_isdigit(int c);
static bool	ft_isspace(int c);

bool	init_args(char	**args, t_param *param)
{
	param->philos_nbr = ft_atoi(args[1]);
	param->time_to_die = ft_atoi(args[2]);
	param->time_to_eat = ft_atoi(args[3]);
	param->time_to_sleep = ft_atoi(args[4]);
	param->eating_times = -1;
	if (args[5])
		param->eating_times = ft_atoi(args[5]);
	if (param->philos_nbr < 1 || param->time_to_die < 1 \
|| param->time_to_eat < 1 || param->time_to_sleep < 1 \
|| (args[5] && param->eating_times < 1))
		return (print_error("All arguments must be a positive int\n"), false);
	return (true);
}

static int	ft_atoi(char *n) //TODO: Handle "+"
{
	long	res;

	res = 0;
	while (ft_isspace(*n))
		n++;
	while (*n)
	{
		if (!ft_isdigit(*n))
			return (-1);
		res = res * 10 + (*n++ - '0');
	}
	if (res > INT_MAX)
		return (-1);
	return (res);
}

static bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static bool	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}
