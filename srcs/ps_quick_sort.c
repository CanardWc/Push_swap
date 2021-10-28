#include <push_swap.h>

int	ps_is_sorted(t_list *pile, int indicator, int len)
{
	int	i;
	int	j;

	while (--len)
	{
		i = *(int *)(pile->content);
		j = *(int *)(pile->next->content);
		if (indicator == 0 && i > j)
			return (1);
		else if (indicator == 1 && i < j)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	ps_get_median(t_list *pile, int len)
{
	int	*list;
	int	j;
	int	i;
	
	list = (int *)malloc(sizeof(int) * len);
	if (list == NULL)
		ps_error();
	i = -1;
	while (++i < len)
	{
		list[i] = *(int *)(pile->content);
		pile = pile->next;
	}
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (list[j] > list[i])
				ft_swap(&list[j], &list[i]);
	}
	i = list[len / 2];
	free(list);
	return (i);
}

void	ps_quick_sort_pile_b(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	int	median;

	if (!ps_is_sorted(pile_b, 1, len))
	{
		while (len--)
			ps_p_instructions("pa", &pile_a, &pile_b, output);
		return ;
	}
	if (len < 4)
		return (ps_simple_sort_pile_b(pile_a, pile_b, len, output));
	median = ps_get_median(pile_b, len);
	ps_descending_pile_b(&pile_a, &pile_b, len, median, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}

void	ps_quick_sort_pile_a(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	int	median;

	if (!ps_is_sorted(pile_a, 0, len))
		return ;
	if (len < 4)
		return (ps_simple_sort_pile_a(pile_a, pile_b, len, output));
	median = ps_get_median(pile_a, len);
	ps_descending_pile_a(&pile_a, &pile_b, len, median, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}
