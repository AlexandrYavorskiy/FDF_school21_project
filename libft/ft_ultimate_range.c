/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:33:50 by rkaley            #+#    #+#             */
/*   Updated: 2019/09/16 15:25:43 by rkaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int *ofints;
	int j;

	j = 0;
	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	ofints = (int*)malloc(sizeof(int) * (max - min));
	while (j < max)
	{
		ofints[j] = min + j;
		j++;
	}
	*range = ofints;
	return (max - min);
}
