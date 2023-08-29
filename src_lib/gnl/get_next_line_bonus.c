/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:42:18 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/29 13:24:15 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: The functions returns a line read from a file descriptor.
** 
** DESCRIPTION:
** 		The get_next_line function return a line read from a file descriptor,
** it can from several fd and never loose track of what has been read.
*/

#include "libft.h"

/* Different from libft join to add gnl protections */

static char	*ft_strjoin_gnl_bonus(char *s1, char *s2)
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

static char	*read_and_add_to_static_str_bonus(char *text_read, int fd)
{
	int		tt_de_lecture;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	tt_de_lecture = 1;
	while (!ft_strchr(text_read, 10) && tt_de_lecture != 0)
	{
		tt_de_lecture = read(fd, buffer, BUFFER_SIZE);
		if (tt_de_lecture == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[tt_de_lecture] = 0;
		text_read = ft_strjoin_gnl_bonus(text_read, buffer);
	}
	free(buffer);
	return (text_read);
}

/* Copies from the static and allocate a string to return from main functions */

static char	*extract_to_line_bonus(char *text_read)
{
	int		i;
	char	*line;

	i = 0;
	if (!text_read[i])
		return (NULL);
	while (text_read[i] && text_read[i] != 10)
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text_read[i] && text_read[i] != 10)
	{
		line[i] = text_read[i];
		i++;
	}
	if (text_read[i] == 10)
	{
		line[i] = text_read[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

/* Allocates a new string to be read and initilize it to the start */

static char	*update_static_str_bonus(char *text_read)
{
	int		i;
	int		j;
	char	*new_text_to_read;

	i = 0;
	while (text_read[i] && text_read[i] != 10)
		i++;
	if (!text_read[i])
	{
		free(text_read);
		return (NULL);
	}
	new_text_to_read = malloc(sizeof(char) * (ft_strlen(text_read) - i + 1));
	if (!new_text_to_read)
		return (NULL);
	i++;
	j = 0;
	while (text_read[i])
		new_text_to_read[j++] = text_read[i++];
	new_text_to_read[j] = 0;
	free(text_read);
	return (new_text_to_read);
}

/* Main function */

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*text_read[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	text_read[fd] = read_and_add_to_static_str_bonus(text_read[fd], fd);
	if (!text_read[fd])
		return (NULL);
	line = extract_to_line_bonus(text_read[fd]);
	text_read[fd] = update_static_str_bonus(text_read[fd]);
	return (line);
}
