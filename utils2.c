/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:41:34 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/05 12:41:35 by aadnane          ###   ########.fr       */
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

// void check_elements(int ac, char **av)
// {
//     int i;

//     (void)ac;
//     i = 1;

//     while (av[i])
//     {
//         if (ft_strlen(av[i]) > 10)
//             ft_error();
//         if (ft_strlen(av[i]) < 10)
//             is_raw_number(av[i]);
//         i++;
//     }
// }

// void   is_raw_number(char *number)
// {
//     int i;

//     i = 0;
//     while(number[i])
//     {
//         i++;
//         if (number[i] == '-' || number[i] == '+')
//             ft_error();
//     }
//     i = 0;
//     while (number[i])
//     {
//         if (number[i] > '9' || number[i] < '0')
//             ft_error();
//         i++;
//     }
//     i = 0;
//     while (number[i])
//     {
//         if (number[i] > INT_MAX || number[i] < INT_MIN)
//             ft_error();
//         i++;
//     }
// }

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