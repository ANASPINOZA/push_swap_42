/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:58 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/17 16:20:19 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes	*stack_a;
	t_nodes	*stack_b;
	t_nodes	*lis_list;
	t_nodes	*max_len;
	char	**arg;

	if (ac == 1)
		exit(1);
	arg = check_elements(ac, av);
	insert_num(arg, &stack_a);
	if (already_sorted(stack_a) == 1)
		exit(1);
	if (size_of_stack(stack_a) <= 5)
		five_elements(&stack_a, &stack_b);
	else
	{	
		lis_list = extract_lis(stack_a);
		max_len = find_max_len(lis_list);
		mark_elements(lis_list, max_len);
		push_non_lis(&stack_a, &stack_b);
		ft_sort(&stack_a, &stack_b);
	}
	return (0);
}
