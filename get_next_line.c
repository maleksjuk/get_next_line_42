/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:35:26 by obanshee          #+#    #+#             */
/*   Updated: 2019/10/04 19:48:25 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*memory_line(char **str, int fd, char **line)
{
	int		len;
	char	*trans;

	if (ft_strchr(str[fd], '\n'))
	{
		len = (int)(ft_strchr(str[fd], '\n') - str[fd]);
		*line = ft_strsub(str[fd], 0, len);
		if (*(str[fd] + len + 1) != '\0')
		{
			trans = ft_strdup(str[fd] + len + 1);
			free(str[fd]);
			str[fd] = trans;
		}
		else
			ft_strclr(str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strclr(str[fd]);
	}
	return (str[fd]);
}

int		kostyl(int ret, char **str, int fd, char **line)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && str[fd][0] == '\0')
	{
		if (*line)
			**line = '\0';
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[100];
	int			ret;
	char		bufer[BUFF_SIZE + 1];
	char		*trans;
	int			kost;

	if (fd < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while ((ret = read(fd, bufer, BUFF_SIZE)) > 0)
	{
		bufer[ret] = '\0';
		trans = ft_strjoin(str[fd], bufer);
		free(str[fd]);
		str[fd] = trans;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	kost = kostyl(ret, str, fd, line);
	if (kost != 1)
		return (kost);
	str[fd] = memory_line(str, fd, line);
	return (1);
}
