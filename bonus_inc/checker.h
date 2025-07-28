/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:06:43 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/16 23:45:31 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../inc/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*		get_next_line Utilitiy Functions		*/
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, const char *s2);

/*		get_next_line Main Functions		*/
void	read_from_file(int fd, char **buffer);
size_t	modified_strlen(const char *s);
char	*extract_line(char *buffer);
void	clean_buffer(char **buffer);
char	*get_next_line(int fd);

/*		Checker Utility Functions		*/
int		ft_strcmp(const char *s1, const char *s2);
void	print_error(t_stack **a, t_stack **b);
void	read_operation(t_stack **a, t_stack **b, char *operation);
void	get_operation(t_stack **a, t_stack **b);
void	write_checker_res(t_stack *a, t_stack *b);

#endif