/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:20:32 by shdorlin          #+#    #+#             */
/*   Updated: 2022/03/17 20:49:50 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *lnew)
{
	t_list	*next;

	if (!alst || !lnew)
		return ;
	if (*alst)
	{
		next = ft_lstlast(*alst);
		next->next = lnew;
		return ;
	}
	*alst = lnew;
}
