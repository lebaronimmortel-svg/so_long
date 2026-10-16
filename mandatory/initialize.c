/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:35:30 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:10 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	initialize_null(t_data *data)
{
	data->xpm->grass = NULL;
	data->xpm->barrier = NULL;
	data->xpm->exit = NULL;
	data->xpm->coll = NULL;
	data->xpm->play_right = NULL;
	data->xpm->play_left = NULL;
	data->xpm->play_up = NULL;
	data->xpm->play_down = NULL;
}

int	initialize(t_data *data)
{
	initialize_null(data);
	if (!initialize_all(data))
		return (0);
	initialize_map(data);
	return (1);
}
