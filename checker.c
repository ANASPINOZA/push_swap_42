/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:15:08 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/17 16:08:22 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes	*stack_a;
	t_nodes	*stack_b;
	char	**arg;
	char	*read;

	if (ac == 1)
		exit(1);
	arg = check_elements(ac, av);
	insert_num(arg, &stack_a);
	read = get_next_line(0);
	while (read)
	{
		if (!stack_a_treatement(&stack_a, &stack_b, read))
		{
			if (!stack_b_treatement(&stack_b, &stack_a, read))
			{
				if (!double_treatment(&stack_a, &stack_b, read))
					ft_error();
			}
		}
		read = get_next_line(0);
	}
	checker_validation(stack_a);
}

int	stack_a_treatement(t_nodes **stack_a, t_nodes **stack_b, char *read)
{
	if (ft_strcmp(read, "ra\n") == 0)
	{
		rotate(stack_a, "");
		return (1);
	}
	else if (ft_strcmp(read, "rra\n") == 0)
	{
		reverse_rotate(stack_a, "");
		return (1);
	}
	else if (ft_strcmp(read, "sa\n") == 0)
	{
		swap(stack_a, "");
		return (1);
	}
	else if (ft_strcmp(read, "pa\n") == 0)
	{
		pop_n_push(stack_b, stack_a, "");
		return (1);
	}
	return (0);
}

int	stack_b_treatement(t_nodes **stack_b, t_nodes **stack_a, char *read)
{
	if (ft_strcmp(read, "rb\n") == 0)
	{
		rotate(stack_b, "");
		return (1);
	}
	else if (ft_strcmp(read, "rrb\n") == 0)
	{
		reverse_rotate(stack_b, "");
		return (1);
	}
	else if (ft_strcmp(read, "sb\n") == 0)
	{
		swap(stack_b, "");
		return (1);
	}
	else if (ft_strcmp(read, "pb\n") == 0)
	{
		pop_n_push(stack_a, stack_b, "");
		return (1);
	}
	return (0);
}

int	double_treatment(t_nodes **stack_a, t_nodes **stack_b, char *read)
{
	if (ft_strcmp(read, "ss\n") == 0)
	{
		swap(stack_a, "");
		swap(stack_b, "");
		return (1);
	}
	else if (ft_strcmp(read, "rr\n") == 0)
	{
		rotate(stack_a, "");
		rotate(stack_b, "");
		return (1);
	}
	else if (ft_strcmp(read, "rrr\n") == 0)
	{
		reverse_rotate(stack_a, "");
		reverse_rotate(stack_b, "");
		return (1);
	}
	else
		ft_error();
	return (0);
}
