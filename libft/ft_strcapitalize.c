/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:08:50 by rkaley            #+#    #+#             */
/*   Updated: 2019/09/16 15:28:28 by rkaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*ft_check(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			if (!((str[i - 1] >= 'a' && str[i - 1] <= 'z')
						|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
						|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
				str[i] = str[i] - 32;
			i++;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')
				|| (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
				str[i] = str[i] + 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char			*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] - 32;
	i++;
	ft_check(str, i);
	return (str);
}
