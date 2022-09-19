/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_under_treatement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:43:38 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/19 16:42:18 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elments(t_nodes **stack)
{
	t_nodes	*tmp;
	t_nodes	*tmp_sec;
	t_nodes	*tmp_trd;

	tmp = *stack;
	tmp_sec = tmp->next;
	tmp_trd = tmp_sec->next;
	if (tmp->data < tmp_sec->data && tmp_sec->data > tmp_trd->data \
	&& tmp->data < tmp_trd->data)
	{
		reverse_rotate(stack, "rra\n");
		swap(stack, "sa\n");
	}
	else if (tmp->data > tmp_sec->data && tmp_sec->data < tmp_trd->data && \
	tmp->data < tmp_trd->data)
		swap(stack, "sa\n");
	three_elments_aux(stack);
}

void	three_elments_aux(t_nodes **stack)
{
	t_nodes	*tmp;
	t_nodes	*tmp_sec;
	t_nodes	*tmp_trd;

	tmp = *stack;
	tmp_sec = tmp->next;
	tmp_trd = tmp_sec->next;
	if (tmp->data < tmp_sec->data && tmp_sec->data > tmp_trd->data && \
	tmp->data > tmp_trd->data)
		reverse_rotate(stack, "rra\n");
	else if (tmp->data > tmp_sec->data && tmp_sec->data < tmp_trd->data && \
	tmp->data > tmp_trd->data)
		rotate(stack, "ra\n");
	else if (tmp->data > tmp_sec->data && tmp_sec->data > tmp_trd->data && \
	tmp->data > tmp_trd->data)
	{
		rotate(stack, "ra\n");
		swap(stack, "sa\n");
	}
}

void	five_elements(t_nodes **stack_a, t_nodes **stack_b)
{
	t_nodes		*small;

	if (size_of_stack(*stack_a) == 2)
	{	
		rotate(stack_a, "ra\n");
		return ;
	}
	while (size_of_stack(*stack_a) > 3)
	{
		small = get_min_element(*stack_a);
		top_element(stack_a, small, 'a');
		pop_n_push(stack_a, stack_b, "pb\n");
	}
	three_elments(stack_a);
	pop_n_push(stack_b, stack_a, "pa\n");
	pop_n_push(stack_b, stack_a, "pa\n");
}
