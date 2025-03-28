/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:04:01 by daxferna          #+#    #+#             */
/*   Updated: 2025/03/28 21:33:57 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// argv[1] -> Nº filosofos / tenedores
// argv[2] -> Tiempo que tarda en morir de hambre 
//				despues de comer/empezar el programa
// argv[3] -> Tiempo que come un filosofo
// argv[4] -> Tiempo que duerme un filosofo
// argv[5] -> Si todos comen este numero de veces,
//				se acaba el programa (Opcional). Si
//				no se indica, acaba cuando uno muere

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return(0);
	}
	(void)argv;
	return (0);
}
