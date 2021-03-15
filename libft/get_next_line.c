/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:24:08 by rkaley            #+#    #+#             */
/*   Updated: 2019/10/23 20:07:05 by rkaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(char **stack, char **line, int fd, int ret)
{
	char		*tmp_stack;
	int			i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i] != '\0')
		i++;
	if (stack[fd][i] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, i);
		tmp_stack = ft_strdup(stack[fd] + i + 1);
		free(stack[fd]);
		stack[fd] = tmp_stack;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else if (stack[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD];
	char		heap[BUFF_SIZE + 1];
	char		*tmp_stack;
	int			ret;

	if ((fd < 0 || fd >= MAX_FD) || !line || (BUFF_SIZE < 1))
		return (-1);
	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strnew(1);
		tmp_stack = ft_strjoin(stack[fd], heap);
		free(stack[fd]);
		stack[fd] = tmp_stack;
		if (ft_strchr(heap, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (stack[fd] == NULL || stack[fd][0] == 0))
		return (0);
	return (ft_newline(stack, line, fd, ret));
}
