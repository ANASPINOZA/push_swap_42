/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:12 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 15:20:58 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_nodes **stack, char *type)
{
    int tmp;

    tmp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = tmp;
    print_instruction(type);
}

void pop_n_push(t_nodes **stack_sender, t_nodes **stack_receiver, char *type)
{
    t_nodes *tmp;

    tmp = *stack_sender;
    *stack_sender = (*stack_sender)->next;

    print_instruction(type);
    push(stack_receiver, tmp->data, tmp->index);
    free(tmp);
}

void rotate(t_nodes **stack, char *type)
{
    t_nodes *tmp;
    t_nodes *sec_tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    sec_tmp = *stack;
    print_instruction(type);
    while (sec_tmp->next != NULL)
    {
        sec_tmp = sec_tmp->next;    
    }
    sec_tmp->next = tmp;
    tmp->next = NULL;
}

void reverse_rotate(t_nodes **stack, char *type)
{
    t_nodes *tmp;
    t_nodes *sec_tmp;

    tmp = *stack;
    print_instruction(type);
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    sec_tmp = tmp->next;
    sec_tmp->next = *stack;
    tmp->next = NULL;
    *stack = sec_tmp;
}