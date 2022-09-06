/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:36 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 10:56:56 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes *get_min_element(t_nodes *stack)
{
    int min;
    t_nodes *ret;

    ret = stack;
    min = stack->data;
    while (stack)
    {
        min = stack->data;
        if (min < ret->data)
            ret = stack;
        stack = stack->next;
    }
    return (ret);
}

void ft_pair(t_nodes **stack_a, t_nodes **stack_b)
{
    t_nodes *tmp;
    t_nodes *sec_tmp;
    t_nodes *trd_tmp;
    
    tmp = *stack_a;
    sec_tmp = tmp->next;
    trd_tmp = *stack_b;
    indexation_elems(*stack_a);
    while (trd_tmp != NULL)
    {
        tmp = *stack_a;
        sec_tmp = tmp->next;
        while (sec_tmp != NULL)
        {
            if (tmp->data < trd_tmp->data && trd_tmp->data < sec_tmp->data)
               trd_tmp->pair_idx = sec_tmp->elmts_indx;
            sec_tmp = sec_tmp->next;
            tmp = tmp->next;
        }
        if (tmp->data < trd_tmp->data)
             trd_tmp->pair_idx = (*stack_a)->elmts_indx;
        if (trd_tmp->pair_idx == -1)
            trd_tmp->pair_idx = get_min_element(*stack_a)->elmts_indx;
        trd_tmp = trd_tmp->next;
    }
}

// void ft_sort(t_nodes *stack_a, t_nodes *stack_b, int index)
// {
//     t_nodes *tmp_a;
//     t_nodes *tmp_b;
//     int     stack_size_b;
//     // int     stack_size_a;
//     int     instr_above;
//     int     instr_below;
//     (void)index;

//     tmp_b = stack_b;
//     tmp_a = stack_a;
//     stack_size_b = size_of_stack(stack_b);
//     // stack_size_a = size_of_stack(stack_a);
//     // indexation_elems(stack_a);
//     indexation_elems(stack_b);
//     while (tmp_b != NULL)
//     {
//         if (tmp_b->elmts_indx >= (stack_size_b / 2))
//         {
//             instr_below = stack_size_b - tmp_b->elmts_indx;
//             while (instr_below)
//             {
//                 rotate_up(&stack_b);
//                 instr_below--;
//             }
//             while (tmp_a != NULL)
//             {
//                 if (tmp_a->elmts_indx == tmp_b->pair_idx)
//                     pop_n_push(&stack_b, &stack_a);
//                 rotate_down(&stack_a);
//                 // tmp_a = tmp_a->next;
//                 tmp_a = stack_a; 
//             }
//             // pop_n_push(&stack_b, &stack_a);
//         }

//         if (tmp_b->elmts_indx < (stack_size_b / 2))
//         {
//             instr_above = tmp_b->elmts_indx;
//             while (instr_above >= 0)
//             {
//                 rotate_down(&stack_b);
//                 instr_above--;
//             }
//         }
//         tmp_b = tmp_b->next;
//     }
// }

// void    moves_count(t_nodes *stack_a, t_nodes *stack_b)
// {
//     t_nodes *tmp_a;
//     t_nodes *tmp_b;
//     int     stack_size_a;
//     int     stack_size_b;

//     indexation_elems(stack_a);
//     indexation_elems(stack_b);
//     stack_size_a = size_of_stack(stack_a);
//     stack_size_b = size_of_stack(stack_b);
//     tmp_a = stack_a;
//     tmp_b = stack_b;

//     while (tmp_b =! NULL)
//     {
//         if (tmp_b->elmts_indx >= (stack_size_b / 2))
//             tmp_b->dis = stack_size_a - tmp_a->elmts_indx;
//         if (tmp_b->elmts_indx < (stack_size_b / 2))
//             tmp_b->dis = tmp_b->elmts_indx;
//     }
// }