/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:54:50 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 14:51:17 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void ft_sort(t_nodes **stack_a, t_nodes **stack_b)
{
    t_nodes *best;
   while (stack_b != NULL) 
   {
        ft_pair(&stack_a, &stack_b);
        calculate_distance(stack_a);
        calculate_distance(stack_b);
        join_distance(stack_a, stack_b);[]
        best = get_less_dis(stack_a);
   }
}