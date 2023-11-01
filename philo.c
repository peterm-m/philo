/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:30:22 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 17:25:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	share_mutex_init(t_share *share)
{
	int	i;

	i = -1;
	while (++i < share->number_of_philo)
	{
		if (pthread_mutex_init(&(share->forks[i]), NULL))
			break ;
	}
	if (i < share->number_of_philo)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&(share->forks[i]));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static t_local	*create_philo(t_share *share)
{
	t_local	*philos;
	int		i;

	philos = (t_local *) malloc(sizeof(t_local) * share->number_of_philo);
	if (philos == NULL)
		return (philos);
	i = -1;
	while (++i < share->number_of_philo)
	{
		philos[i].id = i +1;
		philos[i].eats = 0;
		philos[i].time_from_eat = 0;
		philos[i].share = share;
	}
	return (philos);
}

static int	share_init(t_share *share, t_input *input)
{
	share->number_of_philo = input->number_of_philo;
	share->times[DIE] = input->times[DIE];
	share->times[EAT] = input->times[EAT];
	share->times[SLEEP] = input->times[SLEEP];
	share->number_of_eats = input->number_of_eats;
	if (flag_init(&(share->stop)))
		return (EXIT_FAILURE);
	if (count_init(&(share->complete), 0))
		return (EXIT_FAILURE);
	if (count_init(&(share->end_turn), 0))
		return (EXIT_FAILURE);
	if (count_init(&(share->dies), 0))
		return (EXIT_FAILURE);
	if (count_init(&(share->turn), 0))
		return (EXIT_FAILURE);
	if (share_mutex_init(share))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philosopher(void *input)
{
	t_share	share;
	t_local	*philos;
	int		i;

	if (share_init(&share, input))
		return (EXIT_FAILURE);
	philos = create_philo(&share);
	if (philos == NULL)
		return (EXIT_FAILURE);
	i = -1;
	lock_flag(&share.stop);
	while (++i < share.number_of_philo)
	{
		if (pthread_create(&share.thread[i], NULL, philo_live, &philos[i]))
			break ;
		pthread_detach(share.thread[i]);
	}
	management(&share, philos);
	free(philos);
	return (EXIT_SUCCESS);
}
