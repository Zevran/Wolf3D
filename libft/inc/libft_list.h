/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:33:57 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 03:08:40 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "libft_config.h"

/*
 * Simple linked list structure
 */
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
									void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list					*ft_lsthead(t_list *lst);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef t_bool			(*t_content_comparator)(void *, void *);
t_bool					ft_lsteq(t_list *a, t_list *b,
								t_content_comparator comp);
t_bool					ft_lstneq(t_list *a, t_list *b,
								t_content_comparator comp, size_t n);
t_list					*ft_lstfront(t_list *l);
t_list					*ft_lstback(t_list *l);
t_list					*ft_lstpush_front(t_list **lst, t_list *new);
t_list					*ft_lstpush_back(t_list **lst, t_list *new);
t_list					*ft_lstpop_back(t_list **lst,
										void (*deleter)(void *, size_t));
t_list					*ft_lstpop_front(t_list **lst,
										void (*deleter)(void *, size_t));
size_t					ft_lstsize(t_list *lst);
void					ft_lstswap(t_list *lst1, t_list *lst2);
void					ft_lstsort(t_list *lst, int (*f)(t_list *, t_list *));

#endif
