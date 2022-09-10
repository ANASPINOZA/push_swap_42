/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:41:04 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/10 22:04:25 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
int data;
struct node *next;
int         length;
int         sub;
int         pair_idx;
int         index;
int         elmts_indx;
int         mark_to_push;
int         dis;
int         final_dis;
int         flag;
}t_nodes;

void    swap(t_nodes **stack, char *type);
void    push(t_nodes **head,int value, int index);
void    pop_n_push(t_nodes **stack_sender, t_nodes **stack_receiver, char *type);
void    rotate(t_nodes **stack, char *type);
void    reverse_rotate(t_nodes **stack, char *type);
void    insert_num(int ac, char **av, t_nodes **stack);
t_nodes *extract_lis(t_nodes *stack);
t_nodes *find_max_len(t_nodes *stack);
void    printlis(t_nodes *head);
t_nodes *find_index(t_nodes *stack, int index);
t_nodes *mark_elements(t_nodes *stack, t_nodes *node);
int     size_of_stack(t_nodes *stack);
void    push_non_lis(t_nodes **stack_a, t_nodes **stack_b);
void    ft_pair(t_nodes **stack_a, t_nodes **stack_b);
void    indexation_elems(t_nodes *stack);
int     ft_strlen(char *str);
void    ft_error();
void    check_elements(int ac, char **av);
void    check_duplicate(t_nodes *stack);
void    is_raw_number(char *num);
void    is_integer(char *num);
void    check_is_int_range(char *num, int positive, int negative);
int     ft_strcmp(char *str1, char *str2);
int     ft_max(int n1, int n2);
void    calculate_distance(t_nodes *stack);
void    join_distance(t_nodes *stack_a, t_nodes *stack_b);
t_nodes *get_less_dis(t_nodes *stack);
void    print_instruction(char *str);
t_nodes *find_elem(t_nodes *stack, int index);
void ft_sort(t_nodes **stack_a, t_nodes **stack_b);
void top_element(t_nodes **stack, t_nodes *node, char type);
t_nodes *get_min_elm(t_nodes *stack);
t_nodes *get_min_element(t_nodes *stack);
// void	pr_elemts(t_nodes **stack_a, t_nodes **stack_b); // remove
// void	pr(t_nodes **stack, t_nodes	*node); // remove
int already_sorted(t_nodes *stack);

#endif