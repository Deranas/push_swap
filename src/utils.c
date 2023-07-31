/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:58:07 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/27 18:19:55 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

void    free_stack(t_stack **stack)
{
    t_stack     *buffer;
    

    if (stack || !(*stack))
        return ;
    while (*stack)
    {
        buffer = (*stack)->next;
        free(*stack);
        *stack = buffer;
    }
    // *stack = NULL; - muesste es nicht eh schon null sein?
}
