/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:04:26 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/16 19:04:29 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int i;
    int *array;

    if (min >= max)
    {
        return (NULL);
    }
    array = malloc((max - min) * sizeof(int*));
    if (array == NULL)
    {
        return (0);
    }
    i = 0;
    while (i < max - min)
    {
        array[i] = min + i;
        i++;
    }
    return (array);
}
/*int main(void)
{
    int *array = ft_range(10, 20);
    int i = 0;
    while (array[i] != '\0')
    {
        printf("%d ", array[i]);
        i++;
    }
}*/