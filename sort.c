/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:54:50 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 17:30:42 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

void ft_sort(t_nodes **stack_a, t_nodes **stack_b)
{
    t_nodes *best;
    int middle;
	t_nodes *

    middle = size_of_stack(stack) / 2;
   while (stack_b != NULL) 
   {
        ft_pair(&stack_a, &stack_b);
        calculate_distance(stack_a);
        calculate_distance(stack_b);
        join_distance(stack_a, stack_b);
        best = get_less_dis(stack_b);
        if (best->flag == 9)
        {
			above_mid_rotation(stack_a, stack_b, best);
        //   while ((*stack_b)->data != best->data && \
		//   (*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		//   {
		// 	  rotate(stack_a, "rr");
		// 	  rotate(stack_b, "")
		//   }
		//   while ((*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		//   		rotate(stack_a, "ra");
		//   while ((*stack_b)->data != best->data)
		// 		rotate(stack_a, "rb");	
        } 
		else if (best->flag == 7)
        {
			below_mid_rotation(stack_a, stack_b, best);
        //   while ((*stack_b)->data != best->data && \
		//   (*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		//   {
		// 	  reverse_rotate(stack_a, "rrr");
		// 	  reverse_rotate(stack_b, "")
		//   }
		//   while ((*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		//   		reverse_rotate(stack_a, "rra");
		//   while ((*stack_b)->data != best->data)
		// 		reverse_rotate(stack_a, "rrb");	
        }
   }
}

void top_element(t_nodes **stack, t_nodes *node, char type)
{
     int stack_middle;

     stack_middle = size_of_stack(stack) / 2;
     if (node->elmts_indx < stack_middle)
     {
          while ((*stack)->data != node->data)
          {
               if (type == 'a')
                    rotate(stack, "ra");
               else
                    rotate(stack, "rb");
          }
     }
     else if (node->elmts_indx >= stack_middle)
     {
          while ((*stack)->data != node->data)
          {
               if (type == 'a')
                    reverse_rotate(stack, "rra");
               else
                    reverse_rotate(stack, "rrb");
          }
     }
}

void above_mid_rotation(t_nodes **satck_a, t_nodes **stack_b, t_nodes *best)
{
	while ((*stack_b)->data != best->data && \
		  (*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		  {
			  rotate(stack_a, "rr");
			  rotate(stack_b, "")
		  }
		  while ((*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		  		rotate(stack_a, "ra");
		  while ((*stack_b)->data != best->data)
				rotate(stack_a, "rb");
}
void below_mid_rotation(t_nodes **satck_a, t_nodes **stack_b, t_nodes *best)
{
	while ((*stack_b)->data != best->data && \
		(*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
		{
			reverse_rotate(stack_a, "rrr");
			reverse_rotate(stack_b, "")
		}
		while ((*stack_a)->data != find_elem(*stack_a, best->pair_idx)->data)
			reverse_rotate(stack_a, "rra");
		while ((*stack_b)->data != best->data)
			reverse_rotate(stack_a, "rrb");	
}