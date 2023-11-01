/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:42 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 13:40:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parser(int argc, char const **argv, t_input *input)
{
	input->number_of_philo = (int) get_uint(argv[1]);
	input->times[DIE] = get_uint(argv[2]);
	input->times[EAT] = get_uint(argv[3]);
	input->times[SLEEP] = get_uint(argv[4]);
	input->number_of_eats = -1;
	if (input->number_of_philo <= 0 || input->number_of_philo > 256
		|| input->times[EAT] <= 0 || input->times[EAT] <= 0
		|| input->times[SLEEP] <= 0)
	{
		printf("%s\n", "Incorrect parameter");
		return (EXIT_FAILURE);
	}
	if (argc == 6)
	{
		input->number_of_eats = (int) get_uint(argv[5]);
		if (input->number_of_eats <= 0)
		{
			printf("%s\n", "Incorrect parameter");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char const **argv)
{
	t_input	input;

	if (argc > 6 || argc < 5)
	{
		printf("%s\n", "Incorrect number of parameters");
		return (1);
	}
	if (parser(argc, argv, &input))
		return (EXIT_FAILURE);
	if (philosopher(&input))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
