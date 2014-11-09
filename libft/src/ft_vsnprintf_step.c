/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:23:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:16:11 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>

static int	ft_vsnprintf_step_part1(t_vsnprintf_env *env, va_list args)
{
	char			c;

	c = *env->format;
	if (c == 's' || c == 'S')
		ft_vsnprintf_string(env, args, ft_isupper(c));
	else if (c == 'i' || c == 'l' || c == 'd')
		ft_vsnprintf_signed(env, args, 10);
	else if (c == 'f')
		ft_vsnprintf_float(env, args);
	else
		return (0);
	return (1);
}

static int	ft_vsnprintf_step_part2(t_vsnprintf_env *env, va_list args)
{
	char			c;

	c = *env->format;
	if (c == 'u')
		ft_vsnprintf_unsigned(env, args, 10);
	else if (c == 'c' || c == 'C')
		ft_vsnprintf_char(env, args, ft_isupper(c));
	else if (c == 'p' || c == 'P')
	{
		ft_strncpy(env->offset, "0x", env->max);
		env->offset += 2;
		env->counter += 2;
		ft_vsnprintf_hexa(env, args, ft_isupper(c), 1);
	}
	else
		return (0);
	return (1);
}

static int	ft_vsnprintf_step_part3(t_vsnprintf_env *env, va_list args)
{
	char			c;

	c = *env->format;
	if (c == 'x' || c == 'X')
		ft_vsnprintf_hexa(env, args, ft_isupper(c), 0);
	else
		return (0);
	return (1);
}

void		ft_vsnprintf_step(t_vsnprintf_env *env, va_list args)
{
	if (!env)
		return ;
	if (ft_vsnprintf_step_part1(env, args))
	{
	}
	else if (ft_vsnprintf_step_part2(env, args))
	{
	}
	else if (ft_vsnprintf_step_part3(env, args))
	{
	}
	else
	{
		*env->offset = *env->format;
		env->offset++;
		env->counter++;
	}
	env->format++;
}
