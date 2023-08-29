/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:57:06 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/29 11:46:55 by mpeulet          ###   ########.fr       */
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

/*char	*gnl(int fd)
{
	static t_gnl	gnl;
	char			*lineread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.str = read_and_add_to_static_str(&gnl, fd);
	if (!gnl.str)
		return (NULL);
	lineread = extract_to_line(&gnl);
	if (fd == 0 && ft_strcmp(lineread, "exit\n") == 0)
	{
		free(gnl.str);
		return (lineread);
	}
	gnl.str = update_static_str(&gnl);
	return (lineread);
}*/

char	*gnl(int fd)
{
	static t_gnl	gnl;
	char			*lineread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.str = read_and_add_to_static_str(&gnl, fd);
	if (!gnl.str)
		return (NULL);
	lineread = extract_to_line(&gnl);
	if (fd == 0)
	{
		free(gnl.str);
		return (lineread);
	}
	gnl.str = update_static_str(&gnl);
	return (lineread);
}
