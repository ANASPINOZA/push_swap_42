/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/14 16:59:40 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_non_lis(t_nodes **stack_a, t_nodes **stack_b)
{
    t_nodes *tmp;
    int stack_size;
    // int stack_mid;
    
    tmp = *stack_a;
    // indexation_elems(tmp);
    stack_size = size_of_stack(tmp);
    // stack_mid = size_of_stack(tmp) / 2;
    while (stack_size != 0)
    {
        tmp = *stack_a;
        if (tmp->mark_to_push == 0) /*&& tmp->elmts_indx < stack_mid)*/
            rotate(stack_a, "ra\n");
        // else if (tmp->mark_to_push == 0 && tmp->elmts_indx >= stack_mid)
        //     reverse_rotate(stack_a, "rra\n");
        if (tmp->mark_to_push == 1)
            pop_n_push(stack_a, stack_b, "pb\n");
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
