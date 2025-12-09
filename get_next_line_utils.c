/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:18:52 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/09 13:55:47 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(char *joined, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	joined_len;
	char	*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_len = s1_len + s2_len;
	joined = malloc(joined_len + 1);
	if (joined == NULL)
		return (NULL);
	ft_join(joined, s1, s2);
	return (joined);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size_s;
	int		i;

	i = 0;
	size_s = ft_strlen(s);
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
