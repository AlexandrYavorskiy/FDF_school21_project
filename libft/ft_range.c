/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:35:48 by rkaley            #+#    #+#             */
/*   Updated: 2019/09/16 15:25:27 by rkaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int	*ofints;
	int j;

	j = 0;
	if (min >= max)
		return (NULL);
	ofints = (int*)malloc(sizeof(int) * (max - min));
	while (j < max)
	{
		ofints[j] = min + j;
		j++;
	}
	return (ofints);
}
