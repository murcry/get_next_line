/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digonza2 <digonza2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:12:10 by digonza2          #+#    #+#             */
/*   Updated: 2025/12/23 19:04:08 by digonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line1;
	char	*line2;
	int fd1 = open("pruebas/empty.txt", O_RDONLY);
	int fd2 = open("pruebas/AlbionOnline.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while(line1 || line2)
	{
		printf("%s", line1);
		free(line1);
		line2 = get_next_line(fd2);
		printf("%s", line2);
		free(line2);
		line1 = get_next_line(fd1);
	}
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
	return (0);
}
