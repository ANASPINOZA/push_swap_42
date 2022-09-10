/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:41:34 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/10 22:08:05 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i] && (str1[i] == str2[i]))
        i++;
    return (str1[i] - str2[i]);
}

void ft_error()
{
    write(1, "Error\n", 6);
    exit(1);
}

int already_sorted(t_nodes *stack)
{
    t_nodes *tmp;
    t_nodes *tmp_sec;
    int     stack_size;

    tmp = stack;
    tmp_sec = stack->next;
    stack_size = size_of_stack(stack);
    while (tmp_sec != NULL && stack_size > 0)
    {
        if (tmp->data < tmp_sec->data)
        {
            stack_size--;
            tmp_sec = tmp_sec->next;  
            tmp = tmp->next;     
        }
        else
            return 0;
    }
    return (1);
    // exit(1);
}