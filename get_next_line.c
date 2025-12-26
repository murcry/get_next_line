/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:45 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/26 12:44:44 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads from the file descriptor into a buffer and appends the content
 * to the 'saved' string until a newline is found or EOF is reached.
 *
 * Uses a dynamically allocated buffer of size BUFFER_SIZE. It handles errors
 * by freeing memory and returning NULL if read() fails.
 * @param fd The file descriptor to read from.
 * @param saved The static string containing previously read content.
 * @return The updated 'saved' string containing the new data, or NULL if
 * an error occurs.
 */
static char	*ft_read_to_saved(int fd, char *saved)
{
	char	*buffer;
	int		readed_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed_bytes = 1;
	while (readed_bytes > 0 && (!saved || !ft_strchr(saved, '\n')))
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buffer);
			free(saved);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		saved = ft_strjoin_gnl(saved, buffer);
	}
	free(buffer);
	return (saved);
}

/**
 * @brief Extracts the first line found in the static string 'saved'.
 *
 * This function calculates the length of the line up to the newline character,
 * allocates memory for it, and copies the content. The returned string is
 * NUL-terminated.
 * @param saved The static string containing the buffer read from the file.
 * @return A pointer to the newly allocated string containing the line, 
 * or NULL if memory allocation fails.
 */
static char	*ft_get_line(char *saved)
{
	char	*returned;
	ssize_t	s_returned;
	ssize_t	i;

	i = -1;
	if (!saved || !saved[0])
		return (NULL);
	s_returned = ft_strlen_gnl(saved, '\n') + 1;
	returned = malloc(sizeof(char) * (s_returned + 1));
	if (!returned)
		return (NULL);
	while (++i < s_returned)
		returned[i] = saved[i];
	returned[i] = '\0';
	return (returned);
}

/**
 * @brief Updates the static variable by removing the line that was just read.
 *
 * This function creates a new substring containing only the characters
 * remaining after the first newline found in the current buffer. It then
 * frees the original buffer and updates the pointer to the new substring.
 * @param s A pointer to the address of the static string (saved buffer).
 */

static void	ft_clean_saved(char **saved)
{
	char	*new_saved;
	char	*temp;
	ssize_t	i;

	if (!saved || !*saved)
		return ;
	temp = *saved;
	i = 0;
	while ((*saved)[i] && (*saved)[i] != '\n')
		i++;
	if ((*saved)[i] == '\n')
		i++;
	new_saved = ft_substr(*saved, i, ft_strlen_gnl(*saved, 0) - i);
	free(temp);
	if (!new_saved || !new_saved[0])
	{
		free(new_saved);
		*saved = NULL;
	}
	else
		*saved = new_saved;
}

/**
 * @brief Reads a line from a file descriptor.
 *
 * This function reads from the given file descriptor until a newline character
 * is found or the end of the file is reached. It uses a static buffer to store
 * the remaining data between calls, allowing it to be called repeatedly to
 * read the file line by line.
 * @param fd The file descriptor to read from.
 * @return A pointer to the line read (including the newline character if
 * present), or NULL if an error occurs or if there is nothing left to read.
 */
char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (saved)
			free(saved);
		return (NULL);
	}
	saved = ft_read_to_saved(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_get_line(saved);
	if (!line)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	if (saved)
		ft_clean_saved(&saved);
	return (line);
}
