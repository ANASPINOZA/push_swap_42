/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:41:19 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/14 23:56:17 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * n);
}

void	insert_num(int ac, char **av, t_nodes **stack)
{
	int	i;
	int	j;

	i = ac - 1;
	j = ac - 2;
	while (i > 0)
	{
		push(stack, ft_atoi(av[i]), j);
		i -= 1;
		j -= 1;
	}
	check_duplicate(*stack);
}

void	indexation_elems(t_nodes *stack)
{
	t_nodes	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		tmp->elmts_indx = i;
		tmp->pair_idx = -1;
		tmp->flag = 0;
		tmp = tmp->next;
		i++;
	}
}

int	duplicate_count(char *av)
{
	int	i;
	int	j;
	int	count;
	int	length;

	i = 0;
	j = 1;
	count = 0;
	length = ft_strlen(av);
	while (length > i)
	{
		while (length >= j && av[j])
		{
			if (av[i] == av[j])
				count++;
			j++;
		}
		i++;
		j = i + 1;
	}
	return (count);
}

void	print_instruction(char *str)
{
	write(1, str, ft_strlen(str));
}
