#include <push_swap.h>

void	ps_descending_pile_b(t_list **pile_a, t_list **pile_b, int len, \
		int median, t_list **output)
{
	int	pushed;
	int	pushed_under;

	pushed = len;
	pushed_under = 0;
	while (pushed != (len / 2))
	{
		if (*(int *)((*pile_b)->content) >= median)
		{		
			pushed--;
			ps_p_instructions("pa", pile_a, pile_b, output);
		}
		else
		{
			pushed_under++;
			ps_r_instructions("rb", pile_a, pile_b, output);
		}
	}
	if (len / 2 != ft_lstsize(*pile_b))
		while (pushed_under--)
			ps_rr_instructions("rrb", pile_a, pile_b, output);
}

void	ps_descending_pile_a(t_list **pile_a, t_list **pile_b, int len, \
		int median, t_list **output)
{
	int	pushed;
	int	pushed_under;

	pushed = len;
	pushed_under = 0;
	while (pushed != (len / 2 + len % 2))
	{
		if (*(int *)((*pile_a)->content) < median)
		{		
			pushed--;
			ps_p_instructions("pb", pile_a, pile_b, output);
		}
		else
		{
			pushed_under++;
			ps_r_instructions("ra", pile_a, pile_b, output);
		}
	}
	if ((len / 2 + len % 2) != ft_lstsize(*pile_a))
		while (pushed_under--)
			ps_rr_instructions("rra", pile_a, pile_b, output);
}
