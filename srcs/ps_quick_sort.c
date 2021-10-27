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

t_values	ps_get_values(t_list *pile, int len)
{
	t_values	values;

	values.median = ps_get_median(pile, len);
	values.pushed = len;
	values.pushed_under = 0;
	return(values);
}

void	ps_quick_sort_pile_b(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	t_values	v;

	if (!ps_is_sorted(pile_b, 1, len))
	{
		while (len--)
			ps_p_instructions("pa", &pile_a, &pile_b, output);
		return ;
	}
	if (len < 4)
		return (ps_simple_sort_pile_b(pile_a, pile_b, len, output));
	v = ps_get_values(pile_b, len);
	while (v.pushed != (len / 2))
	{
		if (*(int *)(pile_b->content) >= v.median && v.pushed--)
			ps_p_instructions("pa", &pile_a, &pile_b, output);
		else if (++v.pushed_under)
			ps_r_instructions("rb", &pile_a, &pile_b, output);
	}
	if (len / 2 != ft_lstsize(pile_b))
		while (v.pushed_under--)
			ps_rr_instructions("rrb", &pile_a, &pile_b, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}

void	ps_quick_sort_pile_a(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	t_values	values;

	//ft_printf("len = %d\n", len);
	if (!ps_is_sorted(pile_a, 0, len))
		return ;
	if (len < 4)
		return (ps_simple_sort_pile_a(pile_a, pile_b, len, output));
	values = ps_get_values(pile_a, len);
	while (values.pushed != (len / 2 + len % 2))
	{
		if (*(int *)(pile_a->content) < values.median)
		{
			values.pushed--;
			ps_p_instructions("pb", &pile_a, &pile_b, output);
		}
		else
		{
			values.pushed_under++;
			ps_r_instructions("ra", &pile_a, &pile_b, output);
		}
	}
	if ((len / 2 + len % 2) != ft_lstsize(pile_a))
		while (values.pushed_under--)
			ps_rr_instructions("rra", &pile_a, &pile_b, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}
