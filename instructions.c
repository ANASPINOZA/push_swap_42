/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:12 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/05 12:40:14 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_nodes **stack, char *str)
{
    int tmp;

    tmp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = tmp;
    printf("%s\n", str);
}

void pop_n_push(t_nodes **stack_sender, t_nodes **stack_receiver)
{
    t_nodes *tmp;

    tmp = *stack_sender;
    *stack_sender = (*stack_sender)->next;

    push(stack_receiver, tmp->data, tmp->index);
    free(tmp);
}

void rotate_down(t_nodes **stack)
{
    t_nodes *tmp;
    t_nodes *sec_tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    sec_tmp = *stack;
    while (sec_tmp->next != NULL)
    {
        sec_tmp = sec_tmp->next;    
    }
    sec_tmp->next = tmp;
    tmp->next = NULL;
}

void rotate_up(t_nodes **stack)
{
    t_nodes *tmp;
    t_nodes *sec_tmp;

    tmp = *stack;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    sec_tmp = tmp->next;
    sec_tmp->next = *stack;
    tmp->next = NULL;
    *stack = sec_tmp;
}