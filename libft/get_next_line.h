/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:48:18 by rkaley            #+#    #+#             */
/*   Updated: 2020/07/18 21:34:27 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "sys/stat.h"
# include "unistd.h"
# include "stdlib.h"
# define BUFF_SIZE 7
# define MAX_FD 10240 + 1

int get_next_line(const int fd, char **line);

#endif
