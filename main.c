/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:12:10 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/25 23:12:06 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line;
	int fd1 = open("pruebas/empty.txt", O_RDONLY);
	int fd2 = open("pruebas/AlbionOnline.txt", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
	return (0);
}
