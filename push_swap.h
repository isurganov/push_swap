/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:02:40 by spzona            #+#    #+#             */
/*   Updated: 2022/03/02 21:33:25 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_cmd
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sum;
}				t_cmd;

typedef struct s_node
{
	int				num;
	t_cmd			info;
	struct s_node	*next;
}				t_node;

void	ft_sort_big(t_node **s_a, t_node **s_b, int argc, int *size);
void	ft_sort_small(t_node **s_a, int *size, int argc);
void	ft_sort_middle(t_node **s_a, t_node **s_b, int argc, int *size);
void	ft_error(int a);
int		ft_len_node(t_node *s);
void	ft_init_info(t_node **s_a);
void	ft_free_memory(t_node **s_a);
int		ft_isnum(char *arg);
int		ft_atoi2(const char *str);
void	ft_check_node(t_node *s_a);
void	ft_new_node(t_node **s_a, int argc, char **argv);
int		ft_front_sort(t_node *s_a, int argc);
int		ft_back_sort(t_node *s_b, int argc);
void	ft_sort_b2(t_node **s_a, t_node **s_b, int *size, t_node **need_num);
void	ft_sort_b1(t_node **s_a, t_node **s_b, int *size, t_node **need_num);
void	ft_help_count_iter_for_elem(t_node **s_a);
void	ft_help_find_num(t_node *s_a, t_node *s_b, t_node *max, int *need_n);
void	ft_find_need_num_b(t_node *s_a, t_node *s_b, int *need_n);
void	ft_rot_b(t_node **s_b, int argc, int *size);
void	ft_sort_small1(t_node **s_b, int *size, int argc);
void	ft_count_iter_for_elem(t_node **s_a, t_node **s_b, int a, int b);
void	ft_sort_b(t_node **s_a, t_node **s_b, int *size);
int		ft_count_step_a(t_node *s_a, t_node *min);
void	ft_sort_middle2(t_node **s_a, int k, int i, int *size);
void	ft_sort_middle1(t_node **s_a, t_node **s_b, int point, int *size);
int		ft_len_arg(char **argv);
int		ft_new_stack1(t_node **s_a, char **argv);
t_node	*ft_last(t_node *s);
void	ft_min(t_node *s, t_node **min);
void	ft_max(t_node *s, t_node **max);
void	ft_detect_target_num(t_node *s_a, t_node **need_num);
void	ft_sa(t_node **s_a, char c, int *size);
void	ft_sb(t_node **s_b, char c, int *size);
void	ft_ss(t_node **s_a, t_node **s_b, int *size, char c);
void	ft_pa(t_node **s_a, t_node **s_b, char c, int *size);
void	ft_pb(t_node **s_a, t_node **s_b, char c, int *size);
void	ft_ra(t_node **s_a, char c, int *size);
void	ft_rb(t_node **s_b, char c, int *size);
void	ft_rr(t_node **s_a, t_node **s_b, int *size, char c);
void	ft_rra(t_node **s_a, char c, int *size);
void	ft_rrb(t_node **s_b, char c, int *size);
void	ft_rrr(t_node **s_a, t_node **s_b, int *size, char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_memcmp(void *s1, void *s2, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	ft_command(char *line, t_node **s_a, t_node **s_b, int i);
void	ft_command2(char *line, t_node **s_a, t_node **s_b, int i);
char	*ft_strnew(int size);
int		get_next_line(char **line);
void	ft_read_command(t_node **s_a, t_node **s_b);

#endif
