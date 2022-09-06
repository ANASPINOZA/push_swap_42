/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 15:21:44 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_non_lis(t_nodes **stack_a, t_nodes **stack_b)
{
    t_nodes *tmp;
    int stack_size;

    tmp = *stack_a;
    stack_size = size_of_stack(tmp);

    while (stack_size != 0)
    {
        tmp = *stack_a;
        if (tmp->mark_to_push == 0)
            rotate(stack_a, "ra");
        if (tmp->mark_to_push == 1)
            pop_n_push(stack_a, stack_b, "pb");
        stack_size--;
    }
}

int size_of_stack(t_nodes *stack)
{
    t_nodes *tmp;
    int     stack_size;

    stack_size = 0;
    tmp = stack;
    while (tmp != NULL)
    {
        tmp->elmts_indx = stack_size;
        stack_size++;
        tmp = tmp->next;
    }
    return (stack_size);
}
