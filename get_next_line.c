/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:45 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/16 16:29:41 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new string from the string
 * 's'.
 *
 * This new string starts at index 'start' and has a maximum size of 'len'.
 * @param s The string from which to extract the new string.
 * @param start The start index of the new string in the string 's'.
 * @param len The maximum size of the new string.
 * @return The new string, or NULL if the memory allocation failed.
 */
static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s, 0);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		sub_len = s_len - (size_t)start;
	else
		sub_len = len;
	sub_s = malloc(sub_len + 1);
	if (sub_s == NULL)
		return (NULL);
	while (i < sub_len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

/**
 * @brief Fill the buffer and returns the bytes readed.
 * 
 * This is a static function for the 
 */
static ssize_t	ft_fill_buffer(int fd, char *buffer, char **saved)
{
	char	*temp4free;
	ssize_t	bytes_readed;

	bytes_readed = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_readed <= 0)
		return (bytes_readed);
	buffer[bytes_readed] = '\0';
	if (!*saved)
		*saved = ft_strdup(buffer);
	else
	{
		temp4free = *saved;
		*saved = ft_strjoin(*saved, buffer);
		free(temp4free);
	}
	return (bytes_readed);
}

/**
 * @brief Extracts the first line found in the static string 'saved'.
 *
 * This function calculates the length of the line up to the newline character,
 * allocates memory for it, and copies the content. The returned string is
 * NUL-terminated.
 *
 * @param saved The static string containing the buffer read from the file.
 * @return A pointer to the newly allocated string containing the line, 
 * or NULL if memory allocation fails.
 */
static char	*ft_get_line(char *saved)
{
	char	*returned;
	ssize_t	i;
	ssize_t	s_returned;

	i = 0;
	s_returned = ft_strlen(saved, '\n') + 1;
	returned = malloc(sizeof(char) * s_returned + 1);
	if (!returned)
		return (NULL);
	while (i < s_returned)
	{
		returned[i] = saved[i];
		i++;
	}
	returned[i] = '\0';
	return (returned);
}

static void	ft_clean_saved(char **s)
{
	char	*temp;

	temp = *s;
	*s = ft_substr(*s, ft_strlen(*s, '\n') + 1, ft_strlen(*s, 0));
	free(temp);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*returned;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes;

	bytes = 1;
	returned = NULL;
	while (bytes > 0 && (!saved || ft_strchr(saved, '\n') == NULL))
		bytes = ft_fill_buffer(fd, buffer, &saved);
	if (bytes > 0)
	{
		returned = ft_get_line(saved);
		if (!returned)
			return (returned);
		ft_clean_saved(&saved);
	}
	else
	{
		if (bytes == 0 && saved)
			returned = ft_strdup(saved);
		free(saved);
		saved = NULL;
	}
	return (returned);
}

int	main(void)
{
	int fd = open("AlbionOnline.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
		printf("%s", get_next_line(fd));
	return (0);
}
