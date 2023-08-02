/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:51:02 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/31 16:51:03 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

void cost(t_stack **a, t_stack **b)
{
    t_stack *buffer_a;
    t_stack *buffer_b;
    int size_a;
    int size_b;

    buffer_a = *a;
    buffer_b = *b;
    size_a = stack_size(buffer_a);
    size_b = stack_size(buffer_b);
    while (buffer_b)
    {
        buffer_b->cost_b = buffer_b->curr_pos;
        if (buffer_b->cost_b > size_b / 2)
            buffer_b->cost_b = (size_b - buffer_b->cost_b) * -1;
        buffer_b->cost_a = buffer_b->target_pos;
        if (buffer_b->cost_a > size_a / 2)
            buffer_b->cost_a = (size_a - buffer_b->cost_a);
        buffer_b = buffer_b->next;
    }
}