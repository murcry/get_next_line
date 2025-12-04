/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:45 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/04 13:28:04 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*temp;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_readed;

	bytes_readed = read(fd, buffer, BUFFER_SIZE - 1);
	buffer[bytes_readed] = '\0';
	temp = malloc(ft_strlen(buffer));
	if (temp == NULL)
		return (NULL);
	saved = malloc(ft_strlen(buffer) + ft_strlen(temp));
	saved = ft_strjoin(saved, temp);
}

static ssize_t	strposchar(char *str, char c)
{
	ssize_t	position;
	ssize_t i;

	i = 0;
	
}
