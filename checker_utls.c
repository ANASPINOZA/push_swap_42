/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:54:13 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/17 13:56:09 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_validation(t_nodes *stack_a)
{
	if (already_sorted(stack_a) == 1)
	{
		write(1, "OK\n", 3);
		exit(1);
	}
	else
		write(1, "KO\n", 3);
}
