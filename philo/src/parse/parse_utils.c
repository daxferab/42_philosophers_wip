/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:39:21 by daxferna          #+#    #+#             */
/*   Updated: 2025/06/18 17:39:54 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *n)
{
	long	res;

	res = 0;
	while (ft_isspace(*n) || *n == '+')
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

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}
