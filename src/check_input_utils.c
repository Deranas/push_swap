/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:44:11 by aschmid           #+#    #+#             */
/*   Updated: 2023/07/21 13:57:37 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Push_Swap/push_swap.h"

int issign(char c)
{
    if (!(c == '+' || c == '-'))
		return (0);
	else
		return (1);
}

int isnum(char *argv)
{
    int i;
    
    i = 0;
    if (issign(argv[i]) && argv[i + 1] != '\0')
        i++;
    while (argv[i] && ft_isdigit(argv[i]) == 1)
    {
        if (argv[i] != '\0' && ft_isdigit(argv[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int numcmp(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (s1[i] == '+')
        i++;
    if (s2[j] == '+')
        j++;
    while (s1[i] == s2[j] && s1[i] != '\0')
	{
        i++;
        j++;
    }
	return (s1[i] - s2[j]);
}

int isduplicate(char **argv)
{
    int i;
    int j;

    int i = 1;
    while (argv[i])
    {
        j = 1;
        while (argv[j])
        {
            if (i != j && (numcmp(argv[i], argv[j]) == 0))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

    int iszero(char *argv)
    {
        int i;

        i = 0;
        if (issign(argv[i]) == 1)
            i++;
        while (argv[i] && argv[i] == '0')
            i++;
        if (argv[i] != '\0')
            return (0);
        return (1);
    }
    