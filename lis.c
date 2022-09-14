/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:23 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/14 13:49:56 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max(int n1, int n2)
{
    if(n1 > n2)
        return (n1);
    return (n2);
}

t_nodes *extract_lis(t_nodes *stack)
{
    t_nodes *temp_i;
    t_nodes *temp_j;

    temp_i = stack->next;
    while (temp_i != NULL)
    {
        temp_j = stack;
        while (temp_j != temp_i)
       {
            if (temp_j->data < temp_i->data)
            {
                temp_i->length = ft_max((temp_j->length + 1), temp_i->length);
                if (((temp_j->length + 1) >= temp_i->length))
                    temp_i->sub = temp_j->index;
            }
                temp_j = temp_j->next;
        }
        temp_i = temp_i->next;
    }
    return (stack);
}

t_nodes *find_max_len(t_nodes *stack)
{
    t_nodes *tmp;
    t_nodes *ret;
    int     max;

    tmp = stack;
    ret = stack;
    max = tmp->length;
    while (tmp != NULL)
    {
        max = tmp->length;
        if (max > ret->length)
            ret = tmp;
        tmp = tmp->next;
    }
    return (ret);
}
// t_nodes *find_max_len(t_nodes *stack)
// {
//     t_nodes *tmp;
//     t_nodes *tmp_max;

//     tmp = stack;
//     tmp_max = stack;

//     while (tmp->next != NULL)
//     {
//         if (tmp->length < tmp->next->length)
//             tmp_max = tmp->next;
//         tmp = tmp->next;
//     }
//     return (tmp_max);
// }

t_nodes *find_index(t_nodes *stack, int index)
{ 
    t_nodes *tmp;

    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->index == index)
            return (tmp);
        tmp = tmp->next;
    }
    return NULL;
}

t_nodes *mark_elements(t_nodes *stack, t_nodes *node)
{
    t_nodes *tmp;

    tmp = node;
    while (tmp->sub != -1)
    {
        tmp->mark_to_push = 0;
        tmp = find_index(stack, tmp->sub);
    }
    tmp->mark_to_push = 0;
    return (stack);
}

