/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:36:53 by wonhshin          #+#    #+#             */
/*   Updated: 2023/05/18 21:55:09 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **head, int flag)
{
	t_node	*tail;

	tail = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_node **head, int flag)
{
	t_node	*tail;

	tail = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}

void	rra(t_node **a, int flag)
{
	t_node	*temp;
	t_node	*head;

	head = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	temp->next = NULL;
	head->next = *a;
	*a = head;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int flag)
{
	t_node	*temp;
	t_node	*head;

	head = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	temp->next = NULL;
	head->next = *b;
	*b = head;
	if (flag == 1)
		write(1, "rrb\n", 4);
}
