/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_dlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:17:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:16:33 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DLIST_H
# define LIBFT_DLIST_H

# include <string.h>

/*
** Represents a policy to apply on each node
**	NF_NONE: no flags at all
**	NF_DESTROY_NODE: destroys node in remove functions
**	NF_DESTROY_DATA: destroys user data in remove functions
**	NF_DESTROY_ALL: destroys node & user data in remove functions
**	NF_STATE_HIDDEN: sets the node in hidden state
**	NF_STATE_STANDOUT: sets the node in standout mode
**	NF_STATE_SELECTED: sets the node selected
*/
typedef enum	e_dnode_flag
{
	NF_NONE = 0,
	NF_DESTROY_NODE = 1 << 0,
	NF_DESTROY_DATA = 1 << 1,
	NF_DESTROY_ALL = 1 << 2,
	NF_STATE_HIDDEN = 1 << 3,
	NF_STATE_STANDOUT = 1 << 4,
	NF_STATE_SELECTED = 1 << 5
}				t_dnode_flag;

/*
** Represents a link inside the list
*/
typedef struct	s_dnode
{
	void			*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
	t_dnode_flag	flag;
	size_t			size;
}				t_dnode;

typedef void	(*t_dnode_deleter)(t_dnode *);

/*
** Represents a linked list of t_dnodes
** Tail: the starting node of this list
** Head: the last node of this list
** Size: Optionnal, increments or decrements
** when you add or remove t_dnodes
*/
typedef struct	s_dlist
{
	size_t		size;
	t_dnode		*tail;
	t_dnode		*head;
}				t_dlist;

void			ft_dlist_destroy(t_dlist **list, t_dnode_deleter deleter);
t_dlist			*ft_dlist_dup(const t_dlist *source);
t_dlist			*ft_dlist_copy(t_dlist *dest, const t_dlist *source);
t_dlist			*ft_dlist_init(t_dlist *list);
t_dlist			*ft_dlist_new(void);
void			ft_dlist_remove(t_dlist *list, t_dnode *node,
								t_dnode_deleter deleter);
t_dnode			*ft_dlist_add_back(t_dlist *list, t_dnode *new_node);
t_dnode			*ft_dlist_add_front(t_dlist *list, t_dnode *new_node);
t_dnode			*ft_dlist_push_back(t_dlist *list, t_dnode *new_node);
t_dnode			*ft_dlist_push_front(t_dlist *list, t_dnode *new_node);
void			ft_dlist_clear(t_dlist *list, t_dnode_deleter deleter);

t_dnode			*ft_dnode_init(t_dnode *n, void *data, size_t size, int flags);
t_dnode			*ft_dnode_new(void *data, size_t size, int flags);

#endif
