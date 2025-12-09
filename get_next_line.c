/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:45 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/09 13:59:32 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*temp4free;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_readed;
	ssize_t		pos;

	pos = ft_str4nextline(saved);
	while (pos == -1)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE - 1);
		if (bytes_readed == -1)
		{
			if (saved)
			{
				free(saved);
				saved = NULL;
			}
			return (NULL);
		}
		buffer[bytes_readed] = '\0';
		if (!saved)
			saved = ft_strdup(buffer);
		else
		{
			temp4free = saved;
			saved = ft_strjoin(saved, buffer);
			free(temp4free);
		}
		pos = ft_str4nextline(saved);
	}
}

/**
 * @brief Tell the position of '\n'.
 * 
 * This functions allows us to know the exactly position of the character '\n'
 * in our string.
 * 
 * @param str Is the string we are looking in.
 * 
 * @return It returns the position in our array. It returns -1 if the '\n' isn't
 * found. It returns -2 if the string is NULL.
 */
static ssize_t	ft_str4nextline(char *str)
{
	ssize_t	pos;

	if (str == NULL)
		return (-2);
	else
	{
		pos = 0;
		while (str[pos] != '\n' && str[pos])
			pos++;
		if (pos == (ssize_t)ft_strlen(str))
			pos = -1;
		return (pos);
	}
}
