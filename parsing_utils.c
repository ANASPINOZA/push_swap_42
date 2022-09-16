/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:43 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/16 11:58:51 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_elements(int ac, char **av)
{
	int		i;
	char	**arg;

	(void)ac;
	i = 0;
	arg = av_treatement(av);
	while (arg[i])
	{
		is_raw_number(arg[i]);
		is_integer(arg[i]);
		i++;
	}
	return (arg);
}

// check if the element is a number
void	is_raw_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ((num[i] == '+' || num[i] == '-') && (ft_strlen(&num[i]) >= 2))
			i++;
		if (num[i] < '0' || num[i] > '9')
			ft_error();
		i++;
	}
}

// check if the element is a number in an int range
// (-2147483648 < number < 2147483647)
void	is_integer(char *num)
{
	int	num_len;
	int	positive;
	int	negative;
	int	sig;

	positive = 0;
	negative = 0;
	sig = 0;
	num_len = ft_strlen(num);
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[0] == '+')
			positive = 1;
		if (num[0] == '-')
			negative = 1;
		sig = 1;
	}
	if ((num_len - sig) > 10)
		ft_error();
	if ((num_len - sig) == 10)
		check_is_int_range(num, positive, negative);
}

void	check_is_int_range(char *num, int positive, int negative)
{
	if (negative)
	{
		if ((ft_strcmp(&num[negative], INT_MIN)) > 0)
			ft_error();
	}
	else
	{
		if ((ft_strcmp(&num[positive], INT_MAX)) > 0)
			ft_error();
	}
}

void	check_duplicate(t_nodes *stack)
{
	t_nodes	*tmp1;
	t_nodes	*tmp2;

	tmp1 = stack;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->data == tmp2->data)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
