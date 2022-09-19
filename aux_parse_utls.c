/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_parse_utls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:21:43 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/19 13:40:27 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	**av_treatement(char **av)
{
	int		i;
	char	*str;
	char	**splited;

	i = 1;
	if (av[1])
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
	}
	while (av[i])
	{
		str = ft_strjoin(str, " ");
		if (!str)
			return (NULL);
		str = ft_strjoin(str, av[i++]);
		if (!str)
			return (NULL);
	}
	splited = ft_split(str, ' ');
	if (!splited)
		return (NULL);
	free(str);
	return (splited);
}
