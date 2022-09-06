/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:16:14 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/06 17:17:17 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes *find_elem(t_nodes *stack, int index)
{
    t_nodes *tmp;

    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->elmts_indx == index)
            return (tmp);
        tmp = tmp->next;
    }
    return NULL;
}

