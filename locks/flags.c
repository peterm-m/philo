/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:04 by pedromar          #+#    #+#             */
/*   Updated: 2023/10/31 19:07:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "locks.h"

int	flag_init(t_flag *f)
{
	if (f == NULL)
		return (0);
	return (pthread_mutex_init(&f->flag, NULL));
}

t_flag	*flag_new(void)
{
	t_flag	*f;

	f = (t_flag *)malloc(sizeof(t_flag));
	if (f == NULL)
		return (NULL);
	if (flag_init(f))
	{
		free(f);
		return (NULL);
	}
	return (f);
}

void	flag_delete(t_flag *f)
{
	if (f == NULL)
		return ;
	free(f);
	pthread_mutex_destroy(&f->flag);
}
