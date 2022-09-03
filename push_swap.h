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
int         tmp_idx;
int         index;
int         stack_indx;
int         mark_to_push;
int         elmts_moves
}t_nodes;

void swap(t_nodes **stack, char *str);
void push(t_nodes **head,int value, int index);
void pop_n_push(t_nodes **stack_sender, t_nodes **stack_receiver);
void rotate_down(t_nodes **stack);
void rotate_up(t_nodes **stack);
void insert_num(int ac, char **av, t_nodes **stack);
t_nodes *extract_lis(t_nodes *stack);
t_nodes *find_max_len(t_nodes *stack);
void    printlis(t_nodes *head);
t_nodes *find_index(t_nodes *stack, int index);
t_nodes *mark_elements(t_nodes *stack, t_nodes *node);
int size_of_stack(t_nodes *stack);
void push_non_lis(t_nodes **stack_a, t_nodes **stack_b);
void ft_pair(t_nodes **stack_a, t_nodes **stack_b);
void indexation_elems(t_nodes *stack);
int ft_strlen(char *str);
void ft_error();
void check_elements(int ac, char **av);
void check_duplicate(t_nodes *stack);
void is_raw_number(char *num);
void is_integer(char *num);
void check_is_int_range(char *num, int positive, int negative);
int ft_strcmp(char *str1, char *str2);

#endif