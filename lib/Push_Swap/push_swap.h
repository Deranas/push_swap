/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:39:41 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/24 13:47:15 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
    int     index;
    int     value;
    int     target_pos;
    int     curr_pos;
    int     cost_a;
    int     cost_b;
    struct  s_stack *next;
} t_stack;

int isduplicate(char **argv);
int iszero(char *argv);
int numcmp(const char *s1, const char *s2);
int isnum(char *argv);
int issign(char c);
int check_input(char **argv);

int stack_size(t_stack *stack);

#endif