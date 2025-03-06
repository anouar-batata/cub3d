/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:05:36 by alouriga          #+#    #+#             */
/*   Updated: 2025/01/31 09:08:09 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_next_line(char *reach)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = 0;
	if (!reach || reach[i] == '\0' || !ft_strchr(reach, '\n'))
		return (NULL);
	while (reach[i] != '\n' && reach[i])
		i++;
	while (reach[j] != '\0')
		j++;
	ret = malloc(sizeof(char) * (j - i));
	if (!ret)
		return (free(reach), NULL);
	j = 0;
	i++;
	while (reach[i] != '\0')
	{
		ret[j] = reach[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (free(reach), ret);
}

static char	*cut(char *reach)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reach)
		return (NULL);
	while (reach[i] != '\0' && reach[i] != '\n')
		i++;
	if (reach[i] == '\n')
		j = 1;
	str = malloc(sizeof(char) * (i + 1 + j));
	if (!str)
		return (NULL);
	j = 0;
	while (reach[j] != '\0' && j <= i)
	{
		str[j] = reach[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*reading(int fd, char **reach)
{
	char	*buf;
	char	*str;
	int		i;

	i = 1;
	buf = malloc(sizeof(char) * ((size_t)(BUFFER_SIZE) + 1));
	if (!buf)
		return (reach = ft_free(*reach), NULL);
	while (!ft_strchr(*reach, '\n') && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			*reach = ft_free(*reach);
			return (free(buf), NULL);
		}
		if (i == 0)
			return (free(buf),*reach);
		buf[i] = '\0';
		*reach = ft_strjoin(*reach, buf);
	}
	str = cut(*reach);
	return (free(buf), str);
}

char	*get_next_line(int fd)
{
	static char	*reach;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX
		|| read(fd, 0, 0) == -1)
	{
		reach = ft_free(reach);
		return (NULL);
	}
	line = reading(fd, &reach);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	reach = ft_next_line(reach);
	if (reach && !*reach)
		reach = ft_free(reach);
	return (line);
}
