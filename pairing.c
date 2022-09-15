/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:36 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/15 16:18:02 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*get_min_element(t_nodes *stack_a)
{
	t_nodes	*ret;
	t_nodes	*tmp;
	int		min;

	tmp = stack_a;
	ret = stack_a;
	min = tmp->data;
	while (tmp)
	{
		min = tmp->data;
		if (min < ret->data)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

void	reinit_pair_index(t_nodes *stack)
{
	t_nodes	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->pair_idx = -1;
		tmp = tmp->next;
	}
}

void	ft_pair(t_nodes **stack_a, t_nodes **stack_b)
{
	t_nodes	*tmp;
	t_nodes	*sec_tmp;
	t_nodes	*trd_tmp;

	trd_tmp = *stack_b;
	indexation_elems(*stack_a);
	indexation_elems(*stack_b);
	while (trd_tmp != NULL)
	{
		tmp = *stack_a;
		sec_tmp = (*stack_a)->next;
		while (sec_tmp != NULL)
		{
			if (tmp->data < trd_tmp->data && trd_tmp->data < sec_tmp->data)
				trd_tmp->pair_idx = sec_tmp->elmts_indx;
			sec_tmp = sec_tmp->next;
			tmp = tmp->next;
		}
		if (tmp->data < trd_tmp->data && trd_tmp->data < (*stack_a)->data \
			&& trd_tmp->pair_idx == -1)
			trd_tmp->pair_idx = (*stack_a)->elmts_indx;
		if (trd_tmp->pair_idx == -1)
			trd_tmp->pair_idx = get_min_element(*stack_a)->elmts_indx;
		trd_tmp = trd_tmp->next;
	}
}
