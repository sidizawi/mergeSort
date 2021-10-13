#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long	res;
	int		n;

	res = 0;
	n = 1;
	if (!str)
		exit(1);
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - 48);
	if (*str)
		exit(1);
	res *= n;
	return ((int)res);
}

int	*ft_init(int *lst, int start, int end)
{
	int	len;
	int	*new;
	int	i;

	len = end - start;
	new = malloc(sizeof(int) * len);
	if (!new)
		exit(1);
	i = 0;
	while (start < end)
		new[i++] = lst[start++];
	return (new);
}

void	merge_sort(int *lst, int len)
{
	int	*left;
	int *right;
	int	mid;
	int i;
	int j;
	int k;

	if (len > 1)
	{
		mid = len / 2;
		left = ft_init(lst, 0, mid);
		right = ft_init(lst, mid, len);

		len = len - mid;
		merge_sort(left, mid);
		merge_sort(right, len);

		i = 0;
		j = 0;
		k = 0;
		while (i < mid && j < len)
		{
			if (left[i] < right[j])
				lst[k++] = left[i++];
			else
				lst[k++] = right[j++];
		}
		while (i < mid)
			lst[k++] = left[i++];
		while (j < len)
			lst[k++] = right[j++];
		
		free(left);
		free(right);
	}
}

int	main(int ac, char *av[])
{
	int	*lst;
	int	i;

	lst = malloc(sizeof(int)*(ac - 1));
	i = -1;
	while (++i < ac - 1)
		lst[i] = ft_atoi(av[i+1]);
	merge_sort(lst, ac-1);
	i = 0;
	while (i < ac - 1)
	{
		printf("%i", lst[i++]);
		if (i < ac - 1)
			printf(", ");
	}
	printf("\n");
	free(lst);
	return (0);
}
