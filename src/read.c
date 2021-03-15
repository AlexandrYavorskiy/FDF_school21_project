/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 22:06:34 by rkaley            #+#    #+#             */
/*   Updated: 2020/07/20 15:54:59 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		get_height(char *name)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(name, O_DIRECTORY | O_RDONLY)) > 0)
	{
		ft_putstr("this is directory\n");
		exit(0);
	}
	if ((fd = open(name, O_RDONLY, 0)) <= 0)
	{
		ft_putstr("file does not exist or permission denied\n");
		exit(0);
	}
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *name)
{
	int		width;
	int		fd;
	char	*line;

	if ((fd = open(name, O_RDONLY, 0)) <= 0)
	{
		ft_putstr("file does not exist or permission denied\n");
		exit(0);
	}
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_wdcounter(line, ' ') != width)
		{
			ft_putstr("Invalid map\n");
			exit(0);
		}
		free(line);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *z, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z[i] = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(line);
	free(nums[i]);
	free(nums);
}

void	read_map(char *name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(name);
	data->width = get_width(name);
	data->z = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		fill_matrix(data->z[i++], line);
	close(fd);
	data->z[i] = NULL;
}
