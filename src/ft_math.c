/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:35:32 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 17:40:52 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	abs_f(float number)
{
	return (number < 0 ? -number : number);
}

int		abs(int number)
{
	return (number < 0 ? -number : number);
}
