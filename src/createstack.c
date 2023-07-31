/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:34:40 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/27 17:26:54 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

t_stack *fill_stack(int argc, char **argv, t_stack *stack)
{
    int i;
    long int nb;

    i = 1;
    stack = NULL;
    while (i < argc)
    {
        nb = ft_atoi(argv[i]);
        if (nb < INT_MIN || nb > INT_MAX)
            //exit
        if (i == 1)
            stack = initialize((int) nb);
        else
            add_stack_last(&stack, initialize((int) nb));
        i++;
    }
    return (stack);
}

t_stack *initialize(int value)
{
    t_stack *new;
    new = malloc(1 * sizeof(new));
    if (!new)
        return (NULL);
    new->value = value;
    new->cost_a = -1;
    new->cost_b = -1;
    new->curr_pos = -1;
    new->index = 0;
    new->target_pos = -1;
    new->next = NULL;
    return (new);
}

t_stack *get_stack_last(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

void    add_stack_last(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    last = get_stack_last(*stack);
    last->next = new;
}

void    assign_index(t_stack *stack int size)
{
    t_stack     *buffer;
    t_stack     *highest;
    int          value;
    
    buffer = stack;
    highest = NULL;
    while (--size > 0)
    {
        buffer = stack;
        highest = NULL;
        value = INT_MIN;
        while (buffer)
        {
            if (buffer->value == INT_MIN && buffer->index == 0)
                buffer->index = 1;
            if (buffer->value > value && buffer->index == 0)
            {
                value = buffer->value;
                // buffer = stack unnecessary here?
                highest = buffer;
            }
            else
                buffer = buffer->next;
        }
        if (highest != NULL)
            highest->index = size;
    }
}