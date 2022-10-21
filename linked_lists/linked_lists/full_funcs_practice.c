/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_funcs_practice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:51:26 by uyilmaz           #+#    #+#             */
/*   Updated: 2022/10/16 12:55:59 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct t_Node
{
	int				x;
	struct t_Node	*next;
}t_Node;

void	insert_begginning(t_Node **root, int value)
{
	t_Node *new_node = malloc(sizeof(t_Node));	
	if(new_node == NULL)
		exit (2);
	new_node->x = value;		
	new_node->next = *root;		//creating the new node and binding it.

	*root = new_node;			//	shifting root to the new begginning.
}

void	insert_end(t_Node **root, int value)
{
	t_Node	*new_node = malloc(sizeof(t_Node));	//	allocating and initializing
	if (new_node == NULL)						//	the node.
		exit (3);
	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)		//	if the root is empty then add first and return.
	{
		*root = new_node;
		return;
	}

	t_Node *current = *root;
	while (current->next != NULL)	//	passing till end of the list and adding.
		current = current->next;
	current->next = new_node;
}

void	insert_after(t_Node *location, int value)
{
	t_Node *new_node = malloc(sizeof(t_Node));
	if (new_node == NULL)
		exit (4);
	new_node->x = value;				// initializing and binding the new_node
	new_node->next = location->next;	// with the next one of location.
	
	location->next = new_node;			//	binding location with new_node.
}

void	deallocate(t_Node **root)	//	this func may free all list without 
{									// losing any address.
	t_Node	*current = *root;
	t_Node	*backup;
	
	while (current != NULL)
	{
		backup = current;			//  backing up the current.
		current = current->next;	//	pointing the next struct with current.
		free(backup);				//	free the before one.
	}
	*root = NULL;
}

int	main(void)
{
	//t_Node *root = malloc(sizeof(t_Node));
	//if (!root)
	//	exit (1);
	//root->x = 1;				insert_end function is working for an empty
	//root->next = NULL;     	root too so I don't need a root allocation.

	t_Node *root = NULL;			//    empty root.

	insert_end(&root, 2);
	insert_end(&root, 3);

	insert_begginning(&root, -1);
	insert_begginning(&root, -2);

	insert_after(root->next, 0);		// after then the second element.
	insert_after(root->next->next, 1);	//	after then the third element which is just added.

	t_Node *ptr = root;
	
	while (ptr)
	{
		printf("%d ", ptr->x);
		ptr = ptr->next;
	}

	//free(root->next->next->next);
	//free(root->next->next);
	//free(root->next);
	//free(root);				instead of free all one by one 
	deallocate(&root);		//	deallocate func works pretty well.
}
