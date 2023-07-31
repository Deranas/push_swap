/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:08:04 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/24 12:54:18 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create Functions that check Input:

isallnum
isrange
nodoubles

*/

#include "../lib/Push_Swap/push_swap.h"

int check_input(char **argv)
{
    int i;
    int zeros;

    i = 0;
    zeros = 0;
    if (isduplicate(argv) == 1)
        return (0);
    while (argv[i])
    {
        if (isnum(argv[i]) == 0)
            return (0);
        zeros += iszero(argv[i]);
        i++;
    }
    if (zeros > 1)
        return (0);
    return (1);
}