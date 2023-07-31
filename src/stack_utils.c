/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:34:35 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/27 12:32:47 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

t_stack *get_second_from_last(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}

int stack_size(t_stack *stack)
{
    int size;
    
    size = 0;
    if (!stack)
        return (0);
    while (stack && stack->next)
    {
        stack = stack->next;
        i++;
    }
    return (size);
}