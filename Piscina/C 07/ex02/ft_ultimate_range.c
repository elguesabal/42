/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:16:09 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/17 12:16:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    //int range;

    if (min >= max)
    {
        **range = 0;
        return (0);
    }
    *range = malloc((max - min) * sizeof(int*));
    if (!range)
    {
        **range = 0;
        return (-1);
    }
    i = 0;
    while (i < max - min)
    {
        range[0][i] = min + i;
        i++;
    }
    return (max - min);
}

int main(void)
{
    int array;
    int **range;
    int array = ft_ultimate_range(&range, 10, 20);
    printf("%d ", *range[0]);
}