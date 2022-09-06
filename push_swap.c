/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:58 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 12:45:51 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printlist(t_nodes *head)
{
    t_nodes *tmp;
    tmp = head;
    while (tmp)
    {
        printf("pushed element : %d\n", tmp->data);
        tmp = tmp->next;
    }
}

void push(t_nodes **head,int value, int index)
{
    t_nodes *new_node;
    new_node = malloc(sizeof(t_nodes));
    if (new_node == NULL)
        return;
    new_node->data = value;
    new_node->sub = -1;
    new_node->length = 1;
    new_node->pair_idx = -1;
    new_node->index = index;
    new_node->mark_to_push = 1;
    new_node->dis = 0;
    // new_node->next = NULL;
    new_node->next = *head;
    *head = new_node;
}

int pop(t_nodes **head)
{
    t_nodes *tmp;
    int result;
    if (*head == NULL)
    {
        printf("stack is empty\n");
        return (-555555555);
    }
    result = (*head)->data;
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
    return result;
}

void printlis(t_nodes *head)
{
    t_nodes *tmp;
    tmp = head;
    while (tmp)
    {
        printf("element : [%d] ,index : [%d], length : [%d], sub : [%d] , marked : %d \n", tmp->data, tmp->index, tmp->length, tmp->sub, tmp->mark_to_push);
        tmp = tmp->next;
    }
}

void print_len_lis(t_nodes *head)
{
    t_nodes *tmp;
    tmp = head;
        printf("length : [%d] \n", tmp->length);
}

void print_sorted(t_nodes *head)
{
    t_nodes *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        printf("sorted : [%d] \n", tmp->data);
        tmp = tmp->next;
    }
}


int main(int ac, char **av)
{
    t_nodes *stack_a;
    t_nodes *stack_b;
    // t_nodes *list;
    t_nodes *lis_list;
    t_nodes *max_len;
    t_nodes *sorted;
    t_nodes *best;
    
    check_elements(ac, av);
    insert_num(ac, av, &stack_a);
    printf("stack size %d\n", size_of_stack(stack_a));
    lis_list = extract_lis(stack_a);
    max_len = find_max_len(lis_list);
    printlis(lis_list);
    sorted =  mark_elements(lis_list, max_len);
    printf("fghjdqio\n");
    printlis(sorted);
    push_non_lis(&stack_a, &stack_b);
    ft_sort(&stack_a, &stack_b);

   
    printf("stack a\n");
    printlist(stack_a);
    printf("stack b\n");
    printlist(stack_b);
    ft_pair(&stack_a, &stack_b);
    calculate_distance(stack_a);
    calculate_distance(stack_b);
    join_distance(stack_a, stack_b);
    best = get_less_dis(stack_a);

    return 0;
}
