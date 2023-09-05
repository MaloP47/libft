/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:57:06 by mpeulet           #+#    #+#             */
/*   Updated: 2023/09/05 14:51:09 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: The functions returns a line read from a file descriptor.
** 
** DESCRIPTION:
** 		The get_next_line function return a line read from a file descriptor,
** and never loose track of what has been read.
*/

#include "libft.h"

/* Different from libft join to add gnl protections */

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (free(s1), NULL);
	join = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!join)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (join);
}

/* Reads from fd and add to the static varible */

static char	*read_and_add_to_static_str(t_gnl *gnl, int fd)
{
	gnl->temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!gnl->temp)
		return (NULL);
	gnl->tdl = 1;
	while (!ft_strchr(gnl->str, 10) && gnl->tdl != 0)
	{
		gnl->tdl = read(fd, gnl->temp, BUFFER_SIZE);
		if (gnl->tdl == -1)
		{	
			free(gnl->temp);
			return (NULL);
		}
		gnl->temp[gnl->tdl] = 0;
		gnl->str = ft_strjoin_gnl(gnl->str, gnl->temp);
		if (!gnl->str)
			return (NULL);
	}
	free(gnl->temp);
	return (gnl->str);
}

/* Copies from the static and allocate a string to return from main functions */

static char	*extract_to_line(t_gnl *gnl)
{
	int	i;

	i = 0;
	if (!gnl->str[i])
		return (NULL);
	while (gnl->str[i] && gnl->str[i] != 10)
		i++;
	gnl->temp = malloc((i + 2) * sizeof(char));
	if (!gnl->temp)
		return (NULL);
	i = 0;
	while (gnl->str[i] && gnl->str[i] != 10)
	{
		gnl->temp[i] = gnl->str[i];
		i++;
	}
	if (gnl->str[i] == 10)
	{
		gnl->temp[i] = gnl->str[i];
		i++;
	}
	gnl->temp[i] = 0;
	return (gnl->temp);
}

/* Allocates a new string to be read and initilize it to the start */

static char	*update_static_str(t_gnl *gnl)
{
	int	i;
	int	j;

	i = 0;
	while (gnl->str[i] && gnl->str[i] != 10)
		i++;
	if (!gnl->str[i])
	{
		free(gnl->str);
		gnl->str = 0;
		return (NULL);
	}
	gnl->temp = malloc(sizeof(char) * ((ft_strlen(gnl->str) - i) + 1));
	if (!gnl->temp)
		return (NULL);
	i++;
	j = 0;
	while (gnl->str[i])
		gnl->temp[j++] = gnl->str[i++];
	gnl->temp[j] = 0;
	free(gnl->str);
	return (gnl->temp);
}

/* Main function */

char	*gnl(int fd, int clear)
{
	static t_gnl	gnl;
	char			*lineread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (clear)
	{
		free(gnl.str);
		return (0);
	}
	gnl.str = read_and_add_to_static_str(&gnl, fd);
	if (gnl.str == 0)
	{
		free(gnl.str);
		return (NULL);
	}
	lineread = extract_to_line(&gnl);
	gnl.str = update_static_str(&gnl);
	return (lineread);
}

/*#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	strchr_gnl(char *s, char x)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == x)
			return (1);
		i++;
	}
	return (0);
}

void	*calloc_gnl(int size)
{
	char	*new;
	int		i;

	new = malloc(size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size)
		new[i] = 0;
	return (new);
}

char	*join_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char 	*join;

	if (!s1)
		s1 = calloc_gnl(1);
	join = malloc(strlen_gnl(s1) + strlen_gnl(s2) + 1);
	if (!join)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	free(s1);
	return(join);
}

void	clean_gnl(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != 10)
		i++;
	if (line[i] == 10)
		i++;
	while (line[i])
	{
		buffer[j] = line[i];
		line[i] = 0;
		i++;
		j++;
	}
	buffer[j] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = 0;
	line = join_gnl(line, buffer);
	byte_read = 1;
	while (byte_read > 0 && !strchr_gnl(line, 10))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return(free(line), NULL);
		buffer[byte_read] = 0;
		line = join_gnl(line, buffer);
	}
	if (!line[0])
		return(free(line), NULL);
	else
		clean_gnl(line, buffer);
	return (line);
}*/
