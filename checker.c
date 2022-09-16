/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:15:08 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/16 19:40:47 by aadnane          ###   ########.fr       */
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
		stack_a_treatement(&stack_a, &stack_b);
		stack_b_treatement(&stack_b, &stack_a);
		double_treatment(&stack_a, &stack_b);
		read = get_next_line(0);
	}
	if (already_sorted(stack_a) == 1)
	{
		write(1, "OK\n", 3);
		exit(1);
	}
	else
		write(1, "KO\n", 3);
}

void	stack_a_treatement(t_nodes **stack_a, t_nodes **stack_b)
{
	if (ft_strcmp(read, "ra\n") == 0)
			rotate(&stack_a, "");
		else if (ft_strcmp(read, "rra\n") == 0)
			reverse_rotate(&stack_a, "");
		else if (ft_strcmp(read, "sa\n") == 0)
			swap(&stack_a, "");
		else if (ft_strcmp(read, "pa\n") == 0)
			pop_n_push(&stack_b, &stack_a, "");
}

void	stack_b_treatement(t_nodes **stack_b, t_nodes **stack_a)
{
	if (ft_strcmp(read, "rb\n") == 0)
			rotate(&stack_b, "");
		else if (ft_strcmp(read, "rrb\n") == 0)
			reverse_rotate(&stack_b, "");
		else if (ft_strcmp(read, "sb\n") == 0)
			swap(&stack_b, "");
		else if (ft_strcmp(read, "pb\n") == 0)
			pop_n_push(&stack_b, &stack_b, "");
}

void	double_treatment(t_nodes **stack_a, t_nodes **stack_b)
{
	if (ft_strcmp(read, "ss\n") == 0)
	{
		swap(&stack_a, "");
		swap(&stack_b, "");
	}
	else if (ft_strcmp(read, "rr\n") == 0)
	{
		rotate(&stack_a, "");
		rotate(&stack_b, "");
	}
	else if (ft_strcmp(read, "rrr\n") == 0)
	{
		reverse_rotate(&stack_a, "");
		reverse_rotate(&stack_b, "");
	}
	else
		ft_error();
}