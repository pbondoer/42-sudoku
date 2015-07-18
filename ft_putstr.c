/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanlavi <florent-pro@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:42:54 by fsanlavi          #+#    #+#             */
/*   Updated: 2015/07/18 18:44:47 by fsanlavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		ft_putchar(str[i++]);
}