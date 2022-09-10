/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:39:51 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/10 19:45:58 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes *get_less_dis(t_nodes *stack)
{
    t_nodes *ret;
    t_nodes *tmp;
    int     less_dis;

    ret = stack;
    tmp = stack;
    less_dis = stack->final_dis;
    while (tmp)
    {
        if (less_dis < stack->final_dis)
            ret = stack;
        tmp = tmp->next;
    }
    return (ret);
}

t_nodes *get_min_elm(t_nodes *stack)
{
    t_nodes *ret;
    int     min_elm;

    ret = stack;
    min_elm = stack->data;
    while (stack)
    {
        if (min_elm < stack->data)
            ret = stack;
        stack = stack->next;
    }
    return (ret);
}

void calculate_distance(t_nodes *stack)
{
    t_nodes *tmp;
    int     stack_size;

    stack_size = size_of_stack(stack);
    indexation_elems(stack);
    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->elmts_indx >= (stack_size / 2))
            tmp->dis = stack_size - tmp->elmts_indx;
        else if (tmp->elmts_indx < (stack_size / 2))
            tmp->dis = tmp->elmts_indx;
        tmp = tmp->next;
    }
}

void join_distance(t_nodes *stack_a, t_nodes *stack_b)
{
    int     a_mid;
    int     b_mid;
    t_nodes *tmp_a;
    t_nodes *tmp_b;

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
            {
                if (tmp_b->elmts_indx >= b_mid && tmp_a->elmts_indx >= a_mid)
                {
                    tmp_b->flag = 7;
                    tmp_b->final_dis = ft_max(tmp_a->dis, tmp_b->dis);
                }
                else if ((tmp_b->elmts_indx < b_mid && tmp_a->elmts_indx < a_mid))
                {
                    tmp_b->flag = 9;
                    tmp_b->final_dis = ft_max(tmp_a->dis, tmp_b->dis);
                }
                else
                    tmp_b->final_dis = tmp_b->dis + tmp_a->dis;
            }
            tmp_a = tmp_a->next;
        }
        tmp_b = tmp_b->next;
    }
}

