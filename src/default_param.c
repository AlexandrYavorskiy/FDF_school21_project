/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <rkaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:03:29 by rkaley            #+#    #+#             */
/*   Updated: 2020/07/18 23:48:55 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_param(t_fdf *data)
{
	data->angle = 0.523599;
	data->zoom = 50;
	data->z_scale = 1;
	data->shift_x = 2000 / 3;
	data->shift_y = 1000 / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 1000, "MAP");
}
