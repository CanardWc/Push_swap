#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

void	ps_error(void);

void	ps_s_instructions(char *instr, t_list **pile_a, t_list **pile_b, t_list **output);
void	ps_p_instructions(char *instr, t_list **pile_a, t_list **pile_b, t_list **output);
void	ps_r_instructions(char *instr, t_list **pile_a, t_list **pile_b, t_list **output);
void	ps_rr_instructions(char *instr, t_list **pile_a, t_list **pile_b, t_list **output);

void	ps_optimise_output(t_list **output);

void	ps_descending_pile_a(t_list **pile_a, t_list **pile_b, int len, int median, t_list **output); 
void	ps_descending_pile_b(t_list **pile_a, t_list **pile_b, int len, int median, t_list **output); 

void	ps_simple_sort(t_list *pile_a, t_list *pile_b, t_list **output);
void	ps_simple_sort_pile_a(t_list *pile_a, t_list *pile_b, int len, t_list **output);
void	ps_simple_sort_pile_b(t_list *pile_a, t_list *pile_b, int len, t_list **output);

void	ps_quick_sort_pile_a(t_list *pile_a, t_list *pile_b, int size, t_list **output);

#endif
