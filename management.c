/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:37:04 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/01 19:52:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	management(t_share *share, t_local *philo)
{
	unlock_flag(&(share->stop));
	while (1)
	{
		if (count_get(&share->end_turn) == share->number_of_philo)
		{
			count_set(&share->turn, !(share->turn).value);
			count_set(&share->end_turn, 0);
		}
		else if (count_get(&share->complete) == share->number_of_philo
			|| count_get(&share->dies) != 0)
		{
			lock_flag(&share->stop);
			break ;
		}
	}
	return ;
}
