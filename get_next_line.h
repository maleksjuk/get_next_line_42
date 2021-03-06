/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:05:28 by obanshee          #+#    #+#             */
/*   Updated: 2019/10/04 20:11:41 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

char	*memory_line(char **str, int fd, char **line);
int		kostyl(int ret, char **str, int fd, char **line);
int		get_next_line(const int fd, char **line);

#endif
