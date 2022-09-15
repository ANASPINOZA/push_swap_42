/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:39:51 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/15 16:05:06 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*get_less_dis(t_nodes *stack)
{
	t_nodes	*ret;
	t_nodes	*tmp;
	int		less_dis;

	ret = stack;
	tmp = stack;
	less_dis = tmp->final_dis;
	while (tmp)
	{
		less_dis = tmp->final_dis;
		if (less_dis < ret->final_dis)
		ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

void	calculate_distance(t_nodes *stack)
{
	t_nodes	*tmp;
	int		stack_size;

	stack_size = size_of_stack(stack);
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->elmts_indx > (stack_size / 2))
			tmp->dis = stack_size - tmp->elmts_indx;
		else if (tmp->elmts_indx <= (stack_size / 2))
			tmp->dis = tmp->elmts_indx;
		tmp = tmp->next;
	}
}

void	join_distance(t_nodes *stack_a, t_nodes *stack_b)
{
	int		a_mid;
	int		b_mid;
	t_nodes	*tmp_a;
	t_nodes	*tmp_b;

	tmp_b = stack_b;
	tmp_a = stack_a;
	a_mid = size_of_stack(stack_a) / 2;
	b_mid = size_of_stack(stack_b) / 2;
	while (tmp_b != NULL)
	{
		tmp_a = stack_a;
		while (tmp_a != NULL)
		{
			if (tmp_b->pair_idx == tmp_a->elmts_indx)
				join_and_flag(tmp_a, tmp_b, a_mid, b_mid);
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	join_and_flag(t_nodes *stack_a, t_nodes *stack_b, int mid_a, int mid_b)
{
	if (stack_b->elmts_indx > mid_b && stack_a->elmts_indx > mid_a)
	{
		stack_b->flag = 7;
		stack_b->final_dis = ft_max(stack_a->dis, stack_b->dis);
	}
	else if ((stack_b->elmts_indx <= mid_b \
				&& stack_a->elmts_indx <= mid_a))
	{
		stack_b->flag = 9;
		stack_b->final_dis = ft_max(stack_a->dis, stack_b->dis);
	}
	else
		stack_b->final_dis = stack_b->dis + stack_a->dis;
}
