/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:07:30 by pedromar          #+#    #+#             */
/*   Updated: 2023/10/31 21:05:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "locks.h"

void	wait_flag(t_flag *f)
{
	pthread_mutex_lock(&f->flag);
	pthread_mutex_unlock(&f->flag);
}

void	lock_flag(t_flag *f)
{
	pthread_mutex_lock(&f->flag);
}

void	unlock_flag(t_flag *f)
{
	pthread_mutex_unlock(&f->flag);
}
