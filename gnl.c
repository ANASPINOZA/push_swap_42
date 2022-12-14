/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:39:43 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/16 12:47:50 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[1000000];
	int		i;
	int		n;

	if (fd < 0)
		return (NULL);
	line[0] = 0;
	i = 0;
	n = read(fd, buff, 1);
	while (n && n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
