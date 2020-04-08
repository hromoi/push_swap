/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:54:14 by yperra-f          #+#    #+#             */
/*   Updated: 2019/09/30 20:15:57 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(int *av, int len)
{
	while (len--)
		printf("%d", *av++);
	printf("\n");
}

int quick_select(int *av, int start, int medium, int end)
{
	if (av[start] > av[medium])
	{
		if (av[start] < av[end])
			return (av[start]);
		else if (av[end] > av[medium])
			return (av[end]);
		else
			return (av[medium]);
	}
	else
	{
		if (av[start] > av[end])
			return (av[start]);
		else if (av[end] > av[medium])
			return (av[medium]);
		else
			return (av[medium]);
	}
	return (0);
}

void	swap(int *av, int index1, int index2)
{
	int tmp;

	tmp = av[index1];
	av[index1] = av[index2];
	av[index2] = tmp;
}

int		search_index(int *av, int number, int len)
{
	int i = 0;

	while (len--)
	{
		if (av[i++] == number)
			return (--i);
	}
	return (0);
}

void	quick_sort(int *av, int left, int right, int len)
{
	int pivot;
	int l_left;
	int r_right;
	int tmp;

	// ft_print(av, len);
	if (left < right)
	{
		l_left = left;
		r_right = right;
		pivot = quick_select(av, left, (right + left) / 2, right);
		// printf("pivot - %d\n", pivot);
		while (left < right)
		{
			while (av[left] <= pivot && left < right)
				left++;
			while (av[right] > pivot)
				right--;
			// printf("%d\n%d\n", left, right);
			if (left < right)
				swap(av, left, right);
			// ft_print(av, len);
		}
		swap(av, search_index(av, pivot, len), right);
		pivot = right;
		quick_sort(av, l_left, pivot - 1, len);
		quick_sort(av, pivot + 1, r_right, len);
	}
}

// int		main(void)
// {
// 	int result[11] = { 0, 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
// 	int len = 11;

// 	printf("array - ");
// 	ft_print(result, len);
// 	quick_sort(result, 0, len - 1, len);
// 	printf("array - ");
// 	ft_print(result, len);
// 	return (0);
// }
