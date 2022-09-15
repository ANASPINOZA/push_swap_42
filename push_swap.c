/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:58 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/15 18:44:14 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_nodes **head, int value, int index)
{
	t_nodes	*new_node;

	new_node = malloc(sizeof(t_nodes));
	if (new_node == NULL)
		return ;
	new_node->data = value;
	new_node->sub = -1;
	new_node->length = 1;
	new_node->pair_idx = -1;
	new_node->index = index;
	new_node->mark_to_push = 1;
	new_node->dis = 0;
	new_node->flag = 0;
	// new_node->next = NULL;
	new_node->next = *head;
	*head = new_node;
}

int	pop(t_nodes **head)
{
	t_nodes	*tmp;
	int		result;

	if (*head == NULL)
	{
		write(1, "stack is empty\n", 15);
		return (-555555555);
	}
	result = (*head)->data;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (result);
}

void	printlis(t_nodes *head)
{
	t_nodes	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("content: [%d]: Index[%d] Pair: [%d] Inst: [%d] dis: [%d] \n", tmp->data, tmp->elmts_indx , tmp->pair_idx, tmp->final_dis, tmp->dis);
		tmp = tmp->next;
	}
}

void	print_sorted(t_nodes *head)
{
	t_nodes	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("sorted : [%d] \n", tmp->data);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_nodes	*stack_a;
	t_nodes	*stack_b;
	t_nodes	*lis_list;
	t_nodes	*max_len;

	check_elements(ac, av);
	insert_num(ac, av, &stack_a);
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
