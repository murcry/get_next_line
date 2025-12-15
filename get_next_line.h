/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:12:35 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/15 20:16:22 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Find length of string.
 * 
 * The strlen() function computes the length of the string s.
 * @param *str the string u need to count.
 * @return The number of elements until the terminating NUL character.
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Locates the first occurrence of the character 'c' in the string 's'.
 * 
 * The character 'c' is converted to a char. The terminating null character 
 * is considered to be part of the string; therefore if 'c' is '\0', 
 * the function locates the terminating '\0'.
 * @param s The string to be searched.
 * @param c The character to be searched (passed as an int).
 * @return A pointer to the located character, or NULL if the character 
 * does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatenate 2 strings in a new string.
 * 
 * Allocate (with malloc()) and returns a new string resulting from the
 * concatenation of s1 and s2.
 * @param *s
 * @param c
 * @return the new string; NULL if the memory allocation failed.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string s.
 * 
 * Memory for the new string is obtained with malloc(), and can be freed with
 * free().
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if insufficient memory was
 * available.
 */
char	*ft_strdup(const char *s);

/** 
 * @brief Reads a line from a file descriptor.
 *
 * This function reads from the file descriptor 'fd' and returns the next line,
 * including the newline character, unless the end of the file is reached
 * without a newline.
 * @param fd The file descriptor to read from.
 * @return The line that was read as a null-terminated string.
 * Returns NULL if an error occurs or if the end of the file is reached
 * and there is nothing left to read. The caller must free the returned string.
 */
char	*get_next_line(int fd);

#endif