/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <rkaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:29:01 by rkaley            #+#    #+#             */
/*   Updated: 2020/07/18 23:52:20 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_fdf *data)
{
	char *menu;

	menu = "up, down, left, right: move map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0x03fc35, menu);
	menu = "8, 2 -zoom; 4, 6  -rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x03fc35, menu);
	menu = "Esc - exit";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x03fc35, menu);
	menu = "9, 3 - scale z coordiante";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x03fc35, menu);
}
