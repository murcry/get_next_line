/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:14:50 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/26 12:44:47 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Concatenates 's1' and 's2', and frees 's1'.
 *
 * Designed for GNL, this function treats a NULL 's1' as an empty string.
 * It allocates memory for the result, copies the data, and crucially,
 * frees the original 's1' to prevent memory leaks during the loop.
 *
 * @param s1 The accumulator string (will be freed).
 * @param s2 The buffer string to append (will NOT be freed).
 * @return A pointer to the new concatenated string, or NULL if allocation fails.
 */
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	ssize_t	i;
	ssize_t	j;

	if (!s1)
		join = ft_strdup(s2);
	else
	{
		join = malloc(ft_strlen_gnl(s1, 0) + ft_strlen_gnl(s2, 0) + 1);
		if (!join)
		{
			free(s1);
			return (NULL);
		}
		i = -1;
		while (s1[++i])
			join[i] = s1[i];
		j = -1;
		while (s2[++j])
			join[i + j] = s2[j];
		join[i + j] = '\0';
		free(s1);
	}
	return (join);
}

/**
 * @brief Computes the length of the string s until de char c (passed as an int)
 * is found.
 *
 * @param s The string to measure.
 * @param c The character we are looking for, if it's 0 we just want to know the
 * length of the str.
 * @return The number of characters that precede the terminating NUL character.
 */
size_t	ft_strlen_gnl(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		while (str[i])
			i++;
	else
	{
		while (str[i] && str[i] != (char)c)
			i++;
	}
	return (i);
}

/**
 * @brief Locates the first occurrence of character c in string s.
 *
 * @param s The string to search.
 * @param c The character to locate.
 * @return A pointer to the first occurrence of the character c in the string s, 
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			car;

	car = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == car)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == car)
		return ((char *)&s[i]);
	return (NULL);
}

/**
 * @brief returns a pointer to a new string which is a duplicate of the string s.
 * Memory for the new string is obtained with malloc(3).
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if insufficient memory 
 * was available.
 */
char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size_s;
	int		i;

	i = 0;
	size_s = ft_strlen_gnl(s, 0);
	copy = malloc(size_s + 1);
	if (copy == NULL)
		return (NULL);
	while (i < (int)(size_s))
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen_gnl(s, 0);
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
