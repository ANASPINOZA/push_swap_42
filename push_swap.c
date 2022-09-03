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
    new_node->tmp_idx = 0;
    new_node->index = index;
    new_node->mark_to_push = 1;
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
    // int poped;

    // push(&stack_a,3);
    // push(&stack_a,2);
    // push(&stack_a,1);
    // push(&stack_b,3);
    // push(&stack_b,2);
    // push(&stack_b,1);
    // i shoulde make check stack function to check if elements are valide or not here,
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
   printf("stack a\n");
    printlist(stack_a);
   printf("stack b\n");
    printlist(stack_b);
    ft_pair(&stack_a, &stack_b);

    // print_len_lis(max_len);
    // printf("length : %d", max_len->length);
    /*fourth instruction*/
    // rotate_up(&stack_a);
    // rotate_up(&stack_a);
    // printlist(stack_a);
    /*third instructions*/
    // rotate_down(&stack_a);
    // printlist(list);

    /*secend intstructions*/
    // printlist(stack_b);
    // pop_n_push(&stack_a, &stack_b);
    // printf("-----------------\n");
    // printlist(stack_b);
    // printf("-----------------\n");
    // printlist(stack_a);

    // sa(&head);
    //    while ((poped = pop(&head)) != -555555555)
    // {
    //     printf("poped element : %d\n", poped);
    // }
    // printf("pushed element : %d\n", result);

    
    return 0;
}
