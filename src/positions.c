/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:14:22 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/31 16:30:45 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

static void assign_pos(t_stack **stack)
{
    t_stack *buffer;
    int i;

    i = 0;
    buffer = *stack;
    while (buffer)
    {
        buffer->curr_pos = i;
        i++;
        buffer = buffer->next;
    }
}

int lowest_index_pos(t_stack **stack)
{
    t_stack *buffer;
    int     low_index;
    int     low_pos;

    assign_pos(stack);
    buffer = *stack;
    low_index = INT_MAX;
    low_pos = buffer->curr_pos;
    while (buffer)
    {
        if (buffer->index < low_index)
        {
            low_index = buffer->index;
            low_pos = buffer->curr_pos;
        }
        buffer = buffer->next;
    }
    return (low_pos);
}

static int get_target_pos(t_stack **a, int index_b, int target_idx, int target_pos)
{
    t_stack *buffer;
    
    buffer = *a;
    while (buffer)
    {
        if (buffer->index > index_b && buffer->index < target_idx)
        {
            target_idx = buffer->index;
            target_pos = buffer->curr_pos;
        }
        buffer = buffer->next;
    }
    if (target_idx != INT_MAX)
        return (target_pos);
    buffer = *a;
    while (buffer)
    {
        if (target_idx > buffer->index)
        {
            target_idx = buffer->index;
            target_pos = buffer->curr_pos;
        }
        buffer = buffer->next;
    }
    return (target_pos);
}

void assign_target_pos(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *buffer;
    int target_pos;

    buffer = *stack_b;
    assign_pos(stack_a);
    assign_pos(stack_b);
    target_pos = 0;
    while (buffer)
    {
        target_pos = get_target_pos(stack_a, buffer->index, INT_MAX, target_pos);
        buffer->target_pos = target_pos;
        buffer = buffer->next;
    }
}